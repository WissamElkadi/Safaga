#pragma once

#include <unordered_map>

#include <glad/glad.h> 

#include "Types.h"

namespace Safaga
{
	namespace Render
	{
		static std::unordered_map<Type, GLenum> TypeMapper =
		{
			{Type::BYTE                      ,  GL_BYTE                 },
			{Type::UNSIGNED_BYTE             ,  GL_UNSIGNED_BYTE        },
			{Type::SHORT                     ,  GL_SHORT                },
			{Type::UNSIGNED_SHORT            ,  GL_UNSIGNED_SHORT       },
			{Type::INT                       ,  GL_INT                  },
			{Type::UNSIGNED_INT              ,  GL_UNSIGNED_INT         },
			{Type::FLOAT		             ,  GL_FLOAT                }

		};

		static std::unordered_map<ShaderType, GLenum> ShaderTypeMapper =
		{
			{ShaderType::VERTEX               ,GL_VERTEX_SHADER         },
			{ShaderType::GEOMETRY             ,GL_GEOMETRY_SHADER       },
			{ShaderType::FRAGMENT             ,GL_FRAGMENT_SHADER       }
		};


		static std::unordered_map<DrawingPrimitive, GLenum> DrawingPrimitiveMapper =
		{
			{ DrawingPrimitive::POINTS         ,  GL_POINTS 		    },
			{ DrawingPrimitive::LINES          ,  GL_LINES 		        },
			{ DrawingPrimitive::LINE_LOOP      ,  GL_LINE_LOOP 	        },
			{ DrawingPrimitive::LINE_STRIP     ,  GL_LINE_STRIP  	    },
			{ DrawingPrimitive::TRIANGLES      ,  GL_TRIANGLES    	    },
			{ DrawingPrimitive::TRIANGLE_STRIP ,  GL_TRIANGLE_STRIP     },
			{ DrawingPrimitive::TRIANGLE_FAN   ,  GL_TRIANGLE_FAN       }
		};

		static std::unordered_map<PixelFormat, GLenum> PixelFormatMapper =
		{
			{ PixelFormat::RGB                 ,  GL_RGB      		     },
			{ PixelFormat::RGBA                ,  GL_RGBA   	         }
		};

		static std::unordered_map<DataType, GLenum> DataTypeMapper =
		{
			{ DataType::BYTE                 ,  GL_BYTE      		     },
			{ DataType::UNSIGNED_BYTE        ,  GL_UNSIGNED_BYTE 	     },
			{ DataType::SHORT                ,  GL_SHORT 	             },
			{ DataType::UNSIGNED_SHORT       ,  GL_UNSIGNED_SHORT 	     },
			{ DataType::INT                  ,  GL_INT 	                 },
			{ DataType::UNSIGNED_INT         ,  GL_UNSIGNED_INT 	     },
			{ DataType::FLOAT                ,  GL_FLOAT         	     }
		};

		static std::unordered_map<TextureType, GLenum> TextureTypeMapper =
		{
			{ TextureType::TEXTURE_1D         ,  GL_TEXTURE_1D   		},
			{ TextureType::TEXTURE_2D         ,  GL_TEXTURE_2D   		},
			{ TextureType::TEXTURE_3D         ,  GL_TEXTURE_3D   		},
		};

		static std::unordered_map<TextureWrap, GLenum> TextureWrapMapper =
		{
			{ TextureWrap::REPEAT                                   ,  GL_REPEAT       		      },
			{ TextureWrap::MIRRORED_REPEAT                          ,  GL_MIRRORED_REPEAT   	  },
			{ TextureWrap::CLAMP_TO_EDGE                            ,  GL_CLAMP_TO_EDGE   	      },
			{ TextureWrap::CLAMP_TO_BORDER                          ,  GL_CLAMP_TO_BORDER   	  }
		};

		static std::unordered_map<TextureFilter, GLenum> TextureFilterMapper =
		{
			{ TextureFilter::NEAREST                                ,  GL_NEAREST      		       },
			{ TextureFilter::LINEAR                                 ,  GL_LINEAR   	               }
		};

		static std::unordered_map<MipmapSwitchingFilter, GLenum> MipmapSwitchingFilterMapper =
		{
			{ MipmapSwitchingFilter::LINEAR_MIPMAP_LINEAR            ,  GL_LINEAR_MIPMAP_LINEAR    	},
			{ MipmapSwitchingFilter::LINEAR_MIPMAP_NEAREST           ,  GL_LINEAR_MIPMAP_NEAREST    },
			{ MipmapSwitchingFilter::NEAREST_MIPMAP_LINEAR           ,  GL_NEAREST_MIPMAP_LINEAR    },
			{ MipmapSwitchingFilter::NEAREST_MIPMAP_NEAREST          ,  GL_NEAREST_MIPMAP_NEAREST	}
		};

		static std::unordered_map<TextureUnit, std::pair<GLenum, int>> TextureUnitMapper =
		{
			{ TextureUnit::TEXTURE0        ,  {  GL_TEXTURE0    ,     0  } },
			{ TextureUnit::TEXTURE1        ,  {  GL_TEXTURE1    ,     1  } },
			{ TextureUnit::TEXTURE2        ,  {  GL_TEXTURE2    ,     2  } },
			{ TextureUnit::TEXTURE3        ,  {  GL_TEXTURE3    ,     3  } },
			{ TextureUnit::TEXTURE4        ,  {  GL_TEXTURE4    ,     4  } },
			{ TextureUnit::TEXTURE5        ,  {  GL_TEXTURE5    ,     5  } },
			{ TextureUnit::TEXTURE6        ,  {  GL_TEXTURE6    ,     6  } },
			{ TextureUnit::TEXTURE7        ,  {  GL_TEXTURE7    ,     7  } },
			{ TextureUnit::TEXTURE8        ,  {  GL_TEXTURE8    ,     8  } },
			{ TextureUnit::TEXTURE9        ,  {  GL_TEXTURE9    ,     9  } },
			{ TextureUnit::TEXTURE10       ,  {  GL_TEXTURE10   ,    10  } },
			{ TextureUnit::TEXTURE11       ,  {  GL_TEXTURE11   ,    11  } },
			{ TextureUnit::TEXTURE12       ,  {  GL_TEXTURE12   ,    12  } },
			{ TextureUnit::TEXTURE13       ,  {  GL_TEXTURE13   ,    13  } },
			{ TextureUnit::TEXTURE14       ,  {  GL_TEXTURE14   ,    14  } },
			{ TextureUnit::TEXTURE15       ,  {  GL_TEXTURE15   ,    15  } },
			{ TextureUnit::TEXTURE16       ,  {  GL_TEXTURE16   ,    16  } }
		};

		static std::unordered_map<FillMode, GLenum> FillModeMapper =
		{
			{ FillMode::POINT         ,  GL_POINT},
			{ FillMode::LINE          ,  GL_LINE },
			{ FillMode::FILL          ,  GL_FILL }
		};

		static std::unordered_map<Winding, GLenum> WindingMapper =
		{
			{ Winding::CLOCL_WISE                ,  GL_CW },
			{ Winding::COUNTER_CLOCK_WISE        ,  GL_CCW }
		};

		static std::unordered_map<CullMode, GLenum> CullModeMapper =
		{
			{ CullMode::NONE         ,  GL_NONE },
			{ CullMode::FRONT        ,  GL_FRONT},
			{ CullMode::BACK         ,  GL_BACK }
		};

		static std::unordered_map<CompareFunction, GLenum> CompareFunctionMapper =
		{
			{ CompareFunction::ALWAYS         ,  GL_ALWAYS  },
			{ CompareFunction::EQUAL          ,  GL_EQUAL   },
			{ CompareFunction::GREATER        ,  GL_GREATER },
			{ CompareFunction::GREATER_EQUAL  ,  GL_GEQUAL  },
			{ CompareFunction::LESS           ,  GL_LESS    },
			{ CompareFunction::LESS_EQUAL     ,  GL_LEQUAL  },
			{ CompareFunction::NEVER          ,  GL_NEVER   },
			{ CompareFunction::NOT_EQUAL      ,  GL_NOTEQUAL}
		};

		static std::unordered_map<StencilOperation, GLenum> StencilOperationMapper =
		{
			{ StencilOperation::DECREMENT         ,  GL_DECR        },
			{ StencilOperation::DECREMENT_WRAP    ,  GL_DECR_WRAP   },
			{ StencilOperation::INCREMENT         ,  GL_INCR        },
			{ StencilOperation::INCREMENT_WRAP    ,  GL_INCR_WRAP   },
			{ StencilOperation::INVERT            ,  GL_INVERT      },
			{ StencilOperation::KEEP              ,  GL_KEEP        }, 
			{ StencilOperation::REPLACE           ,  GL_REPLACE     },
			{ StencilOperation::ZERO              ,  GL_ZERO        }
		};

		static std::unordered_map<Face, GLenum> FaceMapper =
		{
			{ Face::FRONT         ,  GL_FRONT          },
			{ Face::BACK          ,  GL_BACK           },
			{ Face::FRONT_BACK    ,  GL_FRONT_AND_BACK }
		};
	}
}