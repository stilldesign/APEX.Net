#include "StdAfx.h"
#include "ApexSdk.h"
#include "Module.h"
#include "ModuleAttribute.h"
#include "UserRenderResourceManager.h"
#include "ApexScene.h"
#include "ApexSceneDesc.h"
#include "ApexBoxShape.h"
#include "Serializer.h"
#include "Asset.h"
#include "Interface.h"
#include "DestructibleAsset.h"

#include <NxDestructibleAsset.h>
#include <NxParameterized.h>

using namespace PhysX::Apex::Modules;

ApexSdk::ApexSdk(PhysX::Physics^ physics)
{
	PxPhysics* physicsPointer = physics->UnmanagedPointer;

	auto cooking = physics->CreateCooking(nullptr);

	NxApexSDKDesc apexDesc;

	auto c = new UserErrorCallback();
	auto a = new UserAllocatorCallback();
	auto rrm = new UserRenderResourceManager();

	apexDesc.physXSDK = physicsPointer;
	apexDesc.cooking = cooking->UnmanagedPointer;
	apexDesc.renderResourceManager = rrm;

	bool validDesc = apexDesc.isValid();

	if (!validDesc)
		throw gcnew PhysX::FailedToCreateObjectException("Failed to create APEX SDK instance, the APEX SDK description is invalid, debug into the isValid() method to see why");

	NxApexCreateError errorCode;
	_apexSdk = NxCreateApexSDK(apexDesc, &errorCode, NX_APEX_SDK_VERSION);

	if (_apexSdk == NULL || errorCode != NxApexCreateError::APEX_CE_NO_ERROR)
		throw gcnew PhysX::FailedToCreateObjectException(String::Format("Failed to create APEX SDK instance. Error code is {0}", (int)errorCode));

}
ApexSdk::~ApexSdk()
{
	this->!ApexSdk();
}
ApexSdk::!ApexSdk()
{
	OnDisposing(this, nullptr);

	if (Disposed)
		return;

	_apexSdk->release();
	_apexSdk = NULL;

	OnDisposed(this, nullptr);
}

bool ApexSdk::Disposed::get()
{
	return (_apexSdk == NULL);
}

//

generic<typename T> where T : Modules::Module, gcnew()
T ApexSdk::CreateModule()
{
	Type^ moduleType = T::typeid;

	auto attributes = moduleType->GetCustomAttributes(ModuleAttribute::typeid, false);

	if (attributes->Length == 0 || !IsInstanceOf<ModuleAttribute^>(attributes[0]))
		throw gcnew ArgumentException("Module requires the ModuleAttribute attribute");

	auto modAttr = (ModuleAttribute^)attributes[0];

	String^ name = modAttr->Name;

	const char* cname = Util::ToUnmanagedString(name);

	NxApexCreateError errorCode;
	NxModule* cmodule = _apexSdk->createModule(cname, &errorCode);

	if (errorCode != 0 || cmodule == NULL)
		throw gcnew ApexException("Failed to create module '{0}'", name);

	auto module = gcnew T();

	module->Init(cmodule, this);

	return (T)module;
}

ApexScene^ ApexSdk::CreateScene(ApexSceneDesc^ desc)
{
	ThrowIfNull(desc, "desc");

	NxApexSceneDesc d = ApexSceneDesc::ToUnmanaged(desc);

	NxApexScene* scene = _apexSdk->createScene(d);

	return gcnew ApexScene(scene, this);
}

ApexBoxShape^ ApexSdk::CreateBoxShape([Optional] Nullable<Vector3> size)
{
	NxApexBoxShape* box = _apexSdk->createApexBoxShape();

	if (size.HasValue)
		box->setSize(UV(size.Value));

	return gcnew ApexBoxShape(box, this);
}

SerializeType ApexSdk::GetSerializerType(array<Byte>^ peekData)
{
	ThrowIfNull(peekData, "peekData");
	if (peekData->Length < 32)
		throw gcnew ArgumentException("The peek data array must be at least 32 bytes");

	BYTE b[32];
	pin_ptr<BYTE> peekDataPin = &peekData[0];
	memcpy(&b, peekDataPin, sizeof(BYTE)* 32);

	NxParameterized::Serializer::SerializeType s = _apexSdk->getSerializeType(&b, 32);

	return ToManagedEnum(SerializeType, s);
}

Serializer^ ApexSdk::CreateSerializer(SerializeType serializeType, PhysX::Apex::ApexScene^ scene)
{
	NxParameterized::Serializer* s = _apexSdk->createSerializer(ToUnmanagedEnum2(NxParameterized::Serializer::SerializeType, serializeType));
	//NxParameterized::Serializer* s = _apexSdk->createSerializer(NxParameterized::Serializer::SerializeType::NST_XML);

	//physx::PxFileBuf* stream = _apexSdk->createStream("C:\\Development\\Temp\\Cube2.apx", physx::PxFileBuf::OPEN_READ_ONLY);

	//NxParameterized::Serializer::DeserializedData data;
	//NxParameterized::Serializer::ErrorType serError = s->deserialize(*stream, data);

	//NxParameterized::Interface *params = data[0];
	//NxApexAsset* asset = _apexSdk->createAsset(params, "Asset Name");

	//NxDestructibleAsset* destructibleAsset = static_cast<NxDestructibleAsset*>(asset);

	//NxParameterized::Interface* descParams = destructibleAsset->getDefaultActorDesc();

	//bool valid = asset->isValidForActorCreation(*descParams, *scene->UnmanagedPointer);

	////NxParameterized::setParamMat44(*descParams, "globalPose", pose);

	//NxApexActor* actor = asset->createApexActor(*descParams, *scene->UnmanagedPointer);

	//NxDestructibleActor* destructibleActor = (NxDestructibleActor*)actor;


	return gcnew Serializer(s, this);
}

Asset^ ApexSdk::CreateAsset(Interface^ i, String^ name)
{
	ThrowIfNullOrDisposed(i, "i");

	char* n = Util::ToUnmanagedString(name);

	NxApexAsset* a = _apexSdk->createAsset(i->UnmanagedPointer, n);

	NxDestructibleAsset* q = (NxDestructibleAsset*)a;

	auto t = q->getActorTransforms();
	int c = q->getChunkCount();
	c = q->getChunkDepth(1);

	//if (dynamic_cast<NxDestructibleAsset*>(a) != NULL)
		return gcnew PhysX::Apex::Modules::Destructible::DestructibleAsset((NxDestructibleAsset*)a, this);

	throw gcnew InvalidOperationException("Cannot create an asset of that type");
}

PhysX::Physics^ ApexSdk::PhysXSdk::get()
{
	return ObjectTable::GetObject<PhysX::Physics^>((intptr_t)_apexSdk->getPhysXSDK());
}

NxApexSDK* ApexSdk::UnmanagedPointer::get()
{
	return _apexSdk;
}