#pragma once

enum class Type
{
	BYTE,
	UNSIGNED_BYTE,
	SHORT,
	UNSIGNED_SHORT,
	INT,
	UNSIGNED_INT,
	FLOAT
};

enum class ShaderType
{
	VERTEX,
	GEOMETRY,
	FRAGMENT
};

enum class DrawingPrimitive
{
	POINTS,
	LINES,
	LINE_LOOP,
	LINE_STRIP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN
};

enum class PixelFormat
{
	RGB,
	RGBA
};

enum class DataType
{
	BYTE,
	UNSIGNED_BYTE,
	SHORT,
	UNSIGNED_SHORT,
	INT,
	UNSIGNED_INT,
	FLOAT
};

enum TextureType
{
	TEXTURE_1D,
	TEXTURE_2D,
	TEXTURE_3D
};

enum class TextureWrap
{
	REPEAT,          // The default behavior for textures.Repeats the texture image.
	MIRRORED_REPEAT, // Same as GL_REPEAT but mirrors the image with each repeat.
	CLAMP_TO_EDGE,   // Clamps the coordinates between 0 and 1. The result is that higher coordinates become clamped to the edge, resulting in a stretched edge pattern.
	CLAMP_TO_BORDER  // Coordinates outside the range are now given a user - specified border color.
};

enum class TextureFilter
{
	NEAREST,
	LINEAR
};

enum class MipmapSwitchingFilter
{
	NEAREST_MIPMAP_NEAREST,     //  takes the nearest mipmap to match the pixel size and uses nearest neighbor interpolation for texture sampling.
	LINEAR_MIPMAP_NEAREST,      //  takes the nearest mipmap level and samples using linear interpolation.
	NEAREST_MIPMAP_LINEAR,      //  linearly interpolates between the two mipmaps that most closely match the size of a pixel and samples via nearest neighbor interpolation.
	LINEAR_MIPMAP_LINEAR        //  linearly interpolates between the two closest mipmaps and samples the texture via linear interpolation.
};

enum class MemoryFormat
{
	FLOAT1,
	FLOAT2,
	FLOAT3,
	FLOAT4,
	INT1,
	INT2,
	INT3,
	INT4,
	UINT1,
	UNIT2,
	UNIT3,
	UNIT4,
	VEC_FLOAT_1,
	VEC_FLOAT_2,
	VEC_FLOAT_3,
	VEC_FLOAT_4,
	VEC_INT_1,
	VEC_INT_2,
	VEC_INT_3,
	VEC_INT_4,
	MAT_FLOAT_2X2,
	MAT_FLOAT_3X3,
	MAT_FLOAT_4X4
};


enum class TextureUnit
{
	TEXTURE0,
	TEXTURE1,
	TEXTURE2,
	TEXTURE3,
	TEXTURE4,
	TEXTURE5,
	TEXTURE6,
	TEXTURE7,
	TEXTURE8,
	TEXTURE9,
	TEXTURE10,
	TEXTURE11,
	TEXTURE12,
	TEXTURE13,
	TEXTURE14,
	TEXTURE15,
	TEXTURE16
};

enum class FillMode
{
	POINT,
	LINE,
	FILL
};

enum class Winding
{
	CLOCL_WISE,
	COUNTER_CLOCK_WISE
};

enum class CullMode
{
	NONE,
	FRONT,
	BACK
};

enum class CompareFunction
{
	NEVER,         // A new value never passes the comparison test.
	LESS,          // A new value passes the comparison test if it is less than the existing value.
	EQUAL,         // A new value passes the comparison test if it is equal to the existing value.
	LESS_EQUAL,    // A new value passes the comparison test if it is less than or equal to the existing value.
	GREATER,       // A new value passes the comparison test if it is greater than the existing value.
	NOT_EQUAL,     // A new value passes the comparison test if it is not equal to the existing value.
	GREATER_EQUAL, // A new value passes the comparison test if it is greater than or equal to the existing value.
	ALWAYS         // A new value always passes the comparison test.
};

enum class VisibilityResultMode
{
	DISABLED, // Does not monitor the samples that pass the depth and stencil tests.
	BOOLEAN,  // Indicates whether samples pass the depth and stencil tests.
	COUNTING  // Counts the samples that pass the depth and stencil tests.
};

enum class StencilOperation
{
	KEEP,            // Keep the current stencil value.
	ZERO,            // Set the stencil value to zero.
	REPLACE,         // Replace the stencil value with the stencil reference value,
	INCREMENT,       // Increase the stencil value by 1 if it is lower than the maximum value.
	DECREMENT,       // Decrease the stencil value by 1 if it is higher than the minimum value.
	INCREMENT_WRAP,  // Same as INCREMENT, but wraps it back to 0 as soon as the maximum value is exceeded.
	DECREMENT_WRAP,  // Same as DECREMENT, but wraps it to the maximum value if it ends up lower than 0.
	INVERT           // Bitwise inverts the current stencil buffer value.
};

enum class FrameBufferType
{
	DEPTH_BUFFER,
	STENCIL_BUFFER,
	COLOR_BUFFER
};

enum class Face
{
	FRONT,
	BACK,
	FRONT_BACK
};
