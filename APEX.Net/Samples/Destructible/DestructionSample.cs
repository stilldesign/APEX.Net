using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using PhysX;
using PhysX.Apex;
using PhysX.Apex.Modules.Destructible;

namespace Apex.Samples.Destructible
{
	public partial class DestructionSample : Form
	{
		public DestructionSample()
		{
			InitializeComponent();
		}

		protected override void OnShown(EventArgs e)
		{
			var foundation = new Foundation(new Errors());

			var physx = new PhysX.Physics(foundation, checkRuntimeFiles: true);

			var apex = new ApexSdk(physx);

			var destructibleModule = apex.CreateModule<PhysX.Apex.Modules.Destructible.DestructibleModule>();

			var desc = destructibleModule.GetDefaultModuleDesc();

			destructibleModule.Initalize(desc);

			var apexSceneDesc = new ApexSceneDesc
			{
				UseDebugRenderable = true
			};

			var apexScene = apex.CreateScene(apexSceneDesc);

			var serializer = apex.CreateSerializer(SerializeType.Binary, apexScene);

			using (var stream = new StreamReader(@"C:\Development\Temp\Cube3.apb"))
			{
				var d = serializer.Deserialize(stream.BaseStream);

				var p = d[0];

				var asset = apex.CreateAsset(p, "Cube2");

				var destructibleAsset = asset as DestructibleAsset;

				var descParams = destructibleAsset.GetDefaultActorDesc();

				bool valid = asset.IsValidForCreation(descParams, apexScene);

				var actor = asset.CreateApexActor(descParams, apexScene);

				var destructibleActor = actor as DestructibleActor;
			}

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
		}
	}

	public class Errors : ErrorCallback
	{
		public override void ReportError(ErrorCode errorCode, string message, string file, int lineNumber)
		{
			Console.WriteLine(message);
		}
	}
}