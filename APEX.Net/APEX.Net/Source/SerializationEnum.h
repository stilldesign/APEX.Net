#pragma once

#include <NxSerializer.h>

namespace PhysX
{
	namespace Apex
	{
		public enum class SerializeType
		{
			XML = NxParameterized::Serializer::SerializeType::NST_XML,
			Binary = NxParameterized::Serializer::SerializeType::NST_BINARY
		};

		public enum class SerializationError
		{
			None = NxParameterized::Serializer::ErrorType::ERROR_NONE,
			Unknown = NxParameterized::Serializer::ErrorType::ERROR_UNKNOWN,
			NotImplemented = NxParameterized::Serializer::ErrorType::ERROR_NOT_IMPLEMENTED,
			InvalidPlatform = NxParameterized::Serializer::ErrorType::ERROR_INVALID_PLATFORM,
			InvalidPlatformName = NxParameterized::Serializer::ErrorType::ERROR_INVALID_PLATFORM_NAME,
			InvalidFileVersion = NxParameterized::Serializer::ErrorType::ERROR_INVALID_FILE_VERSION,
			InvalidFileFormat = NxParameterized::Serializer::ErrorType::ERROR_INVALID_FILE_FORMAT,
			InvalidMagic = NxParameterized::Serializer::ErrorType::ERROR_INVALID_MAGIC,
			InvalidChar = NxParameterized::Serializer::ErrorType::ERROR_INVALID_CHAR,
			StreamError = NxParameterized::Serializer::ErrorType::ERROR_STREAM_ERROR,
			MemoryAllocationFailure = NxParameterized::Serializer::ErrorType::ERROR_MEMORY_ALLOCATION_FAILURE,
			UnalignedMemory = NxParameterized::Serializer::ErrorType::ERROR_UNALIGNED_MEMORY,
			PreserializeFailed = NxParameterized::Serializer::ErrorType::ERROR_PRESERIALIZE_FAILED,
			InternalBufferOverflow = NxParameterized::Serializer::ErrorType::ERROR_INTERNAL_BUFFER_OVERFLOW,
			ObjectCreationFailed = NxParameterized::Serializer::ErrorType::ERROR_OBJECT_CREATION_FAILED,
			ConversionFailed = NxParameterized::Serializer::ErrorType::ERROR_CONVERSION_FAILED,
			Val2stringFailed = NxParameterized::Serializer::ErrorType::ERROR_VAL2STRING_FAILED,
			String2valFailed = NxParameterized::Serializer::ErrorType::ERROR_STRING2VAL_FAILED,
			InvalidTypeAttribute = NxParameterized::Serializer::ErrorType::ERROR_INVALID_TYPE_ATTRIBUTE,
			UnknownXmlTag = NxParameterized::Serializer::ErrorType::ERROR_UNKNOWN_XML_TAG,
			MissingDoctype = NxParameterized::Serializer::ErrorType::ERROR_MISSING_DOCTYPE,
			MissingRootElement = NxParameterized::Serializer::ErrorType::ERROR_MISSING_ROOT_ELEMENT,
			InvalidNesting = NxParameterized::Serializer::ErrorType::ERROR_INVALID_NESTING,
			InvalidAttr = NxParameterized::Serializer::ErrorType::ERROR_INVALID_ATTR,
			InvalidArray = NxParameterized::Serializer::ErrorType::ERROR_INVALID_ARRAY,
			ArrayIndexOutOfRange = NxParameterized::Serializer::ErrorType::ERROR_ARRAY_INDEX_OUT_OF_RANGE,
			InvalidValue = NxParameterized::Serializer::ErrorType::ERROR_INVALID_VALUE,
			InvalidInternalPtr = NxParameterized::Serializer::ErrorType::ERROR_INVALID_INTERNAL_PTR,
			InvalidParamHandle = NxParameterized::Serializer::ErrorType::ERROR_INVALID_PARAM_HANDLE,
			InvalidRelocType = NxParameterized::Serializer::ErrorType::ERROR_INVALID_RELOC_TYPE,
			InvalidDataType = NxParameterized::Serializer::ErrorType::ERROR_INVALID_DATA_TYPE,
			InvalidReference = NxParameterized::Serializer::ErrorType::ERROR_INVALID_REFERENCE
		};
	}
}