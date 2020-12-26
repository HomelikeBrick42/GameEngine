#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	enum class ShaderDataType : uint8
	{
		Invalid,
		Byte,
		Byte2,
		Byte3,
		Byte4,
		UByte,
		UByte2,
		UByte3,
		UByte4,
		Short,
		Short2,
		Short3,
		Short4,
		UShort,
		UShort2,
		UShort3,
		UShort4,
		Int,
		Int2,
		Int3,
		Int4,
		UInt,
		UInt2,
		UInt3,
		UInt4,
		Float,
		Float2,
		Float3,
		Float4,
		Double,
		Double2,
		Double3,
		Double4,
	};

	inline uint64 GetShaderDataTypeElementSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Byte:
		case ShaderDataType::UByte:
			return sizeof(char) * 1;
		case ShaderDataType::Byte2:
		case ShaderDataType::UByte2:
			return sizeof(char) * 2;
		case ShaderDataType::Byte3:
		case ShaderDataType::UByte3:
			return sizeof(char) * 3;
		case ShaderDataType::Byte4:
		case ShaderDataType::UByte4:
			return sizeof(char) * 4;
		case ShaderDataType::Short:
		case ShaderDataType::UShort:
			return sizeof(short) * 1;
		case ShaderDataType::Short2:
		case ShaderDataType::UShort2:
			return sizeof(short) * 2;
		case ShaderDataType::Short3:
		case ShaderDataType::UShort3:
			return sizeof(short) * 3;
		case ShaderDataType::Short4:
		case ShaderDataType::UShort4:
			return sizeof(short) * 4;
		case ShaderDataType::Int:
		case ShaderDataType::UInt:
			return sizeof(int) * 1;
		case ShaderDataType::Int2:
		case ShaderDataType::UInt2:
			return sizeof(int) * 2;
		case ShaderDataType::Int3:
		case ShaderDataType::UInt3:
			return sizeof(int) * 3;
		case ShaderDataType::Int4:
		case ShaderDataType::UInt4:
			return sizeof(int) * 4;
		case ShaderDataType::Float:
			return sizeof(float) * 1;
		case ShaderDataType::Float2:
			return sizeof(float) * 2;
		case ShaderDataType::Float3:
			return sizeof(float) * 3;
		case ShaderDataType::Float4:
			return sizeof(float) * 4;
		case ShaderDataType::Double:
			return sizeof(double) * 1;
		case ShaderDataType::Double2:
			return sizeof(double) * 2;
		case ShaderDataType::Double3:
			return sizeof(double) * 3;
		case ShaderDataType::Double4:
			return sizeof(double) * 4;
		}

		BRICKENGINE_ASSERT(false, "Invalid shader data type!");
		return 0;
	}

	inline uint64 GetShaderDataTypeCount(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Byte:
		case ShaderDataType::UByte:
		case ShaderDataType::Short:
		case ShaderDataType::UShort:
		case ShaderDataType::Int:
		case ShaderDataType::UInt:
		case ShaderDataType::Float:
		case ShaderDataType::Double:
			return 1;
		case ShaderDataType::Byte2:
		case ShaderDataType::UByte2:
		case ShaderDataType::Short2:
		case ShaderDataType::UShort2:
		case ShaderDataType::Int2:
		case ShaderDataType::UInt2:
		case ShaderDataType::Float2:
		case ShaderDataType::Double2:
			return 2;
		case ShaderDataType::Byte3:
		case ShaderDataType::UByte3:
		case ShaderDataType::Short3:
		case ShaderDataType::UShort3:
		case ShaderDataType::Int3:
		case ShaderDataType::UInt3:
		case ShaderDataType::Float3:
		case ShaderDataType::Double3:
			return 3;
		case ShaderDataType::Byte4:
		case ShaderDataType::UByte4:
		case ShaderDataType::Short4:
		case ShaderDataType::UShort4:
		case ShaderDataType::Int4:
		case ShaderDataType::UInt4:
		case ShaderDataType::Float4:
		case ShaderDataType::Double4:
			return 4;
		}

		BRICKENGINE_ASSERT(false, "Invalid shader data type!");
		return 0;
	}

	inline ShaderDataType GetShaderDataTypeBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Invalid:
			return ShaderDataType::Invalid;
		case ShaderDataType::Byte:
		case ShaderDataType::Byte2:
		case ShaderDataType::Byte3:
		case ShaderDataType::Byte4:
			return ShaderDataType::Byte;
		case ShaderDataType::UByte:
		case ShaderDataType::UByte2:
		case ShaderDataType::UByte3:
		case ShaderDataType::UByte4:
			return ShaderDataType::UByte;
		case ShaderDataType::Short:
		case ShaderDataType::Short2:
		case ShaderDataType::Short3:
		case ShaderDataType::Short4:
			return ShaderDataType::Short;
		case ShaderDataType::UShort:
		case ShaderDataType::UShort2:
		case ShaderDataType::UShort3:
		case ShaderDataType::UShort4:
			return ShaderDataType::UShort;
		case ShaderDataType::Int:
		case ShaderDataType::Int2:
		case ShaderDataType::Int3:
		case ShaderDataType::Int4:
			return ShaderDataType::Int;
		case ShaderDataType::UInt:
		case ShaderDataType::UInt2:
		case ShaderDataType::UInt3:
		case ShaderDataType::UInt4:
			return ShaderDataType::UInt;
		case ShaderDataType::Float:
		case ShaderDataType::Float2:
		case ShaderDataType::Float3:
		case ShaderDataType::Float4:
			return ShaderDataType::Float;
		case ShaderDataType::Double:
		case ShaderDataType::Double2:
		case ShaderDataType::Double3:
		case ShaderDataType::Double4:
			return ShaderDataType::Double;
		}

		BRICKENGINE_ASSERT(false, "Invalid shader data type!");
		return ShaderDataType::Invalid;
	}

}
