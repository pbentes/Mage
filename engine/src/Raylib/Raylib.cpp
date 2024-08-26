#include "Raylib.h"

#include <raylib.h>

namespace engine {
    void RegisterRaylibComponents(flecs::world* world) {
        // Structs
        world->component<Vector2>()
            .member<float>("x")
            .member<float>("y");
        
        world->component<Vector3>()
            .member<float>("x")
            .member<float>("y")
            .member<float>("z");

        world->component<Vector4>()
            .member<float>("x")
            .member<float>("y")
            .member<float>("z")
            .member<float>("w");

        world->component<Quaternion>()
            .member<float>("x")
            .member<float>("y")
            .member<float>("z")
            .member<float>("w");
        
        world->component<Matrix>()
            .member<float>("m0")
            .member<float>("m1")
            .member<float>("m2")
            .member<float>("m3")
            .member<float>("m4")
            .member<float>("m5")
            .member<float>("m6")
            .member<float>("m7")
            .member<float>("m8")
            .member<float>("m9")
            .member<float>("m10")
            .member<float>("m11")
            .member<float>("m12")
            .member<float>("m13")
            .member<float>("m14")
            .member<float>("m15");
        
        world->component<Color>()
            .member<unsigned char>("r")
            .member<unsigned char>("g")
            .member<unsigned char>("b")
            .member<unsigned char>("a");

        world->component<Rectangle>()
            .member<float>("x")
            .member<float>("y")
            .member<float>("width")
            .member<float>("height");
        
        world->component<Image>()
            .member<void*>("data")
            .member<int>("width")
            .member<int>("height")
            .member<int>("mipmaps")
            .member<int>("format");

        world->component<Texture>()
            .member<unsigned int>("id")
            .member<int>("width")
            .member<int>("height")
            .member<int>("mipmaps")
            .member<int>("format");

        world->component<Texture2D>()
            .member<unsigned int>("id")
            .member<int>("width")
            .member<int>("height")
            .member<int>("mipmaps")
            .member<int>("format");

        world->component<TextureCubemap>()
            .member<unsigned int>("id")
            .member<int>("width")
            .member<int>("height")
            .member<int>("mipmaps")
            .member<int>("format");

        world->component<RenderTexture>()
            .member<unsigned int>("id")
            .member<Texture>("texture")
            .member<Texture>("depth");

        world->component<RenderTexture2D>()
            .member<unsigned int>("id")
            .member<Texture>("texture")
            .member<Texture>("depth");

        world->component<NPatchInfo>()
            .member<Rectangle>("source")
            .member<int>("left")
            .member<int>("top")
            .member<int>("right")
            .member<int>("bottom")
            .member<int>("layout");

        world->component<GlyphInfo>()
            .member<int>("value")
            .member<int>("offsetX")
            .member<int>("offsetY")
            .member<int>("advanceX")
            .member<Image>("image");

        world->component<Font>()
            .member<int>("baseSize")
            .member<int>("glyphCount")
            .member<int>("glyphPadding")
            .member<Texture2D>("texture")
            .member<Rectangle*>("recs")
            .member<GlyphInfo*>("glyphs");

        world->component<Camera3D>()
            .member<Vector3>("position")
            .member<Vector3>("target")
            .member<Vector3>("up")
            .member<float>("fovy")
            .member<int>("projection");

        world->component<Camera>()
            .member<Vector3>("position")
            .member<Vector3>("target")
            .member<Vector3>("up")
            .member<float>("fovy")
            .member<int>("projection");

        world->component<Camera2D>()
            .member<Vector2>("offset")
            .member<Vector2>("target")
            .member<float>("rotation")
            .member<float>("zoom");

        world->component<Mesh>()
            .member<int>("vertexCount")
            .member<int>("triangleCount")
            .member<float*>("vertices")
            .member<float*>("texcoords")
            .member<float*>("texcoords2")
            .member<float*>("normals")
            .member<float*>("tangents")
            .member<unsigned char*>("colors")
            .member<unsigned short*>("indices")
            .member<float*>("animVertices")
            .member<float*>("animNormals")
            .member<unsigned char*>("boneIds")
            .member<float*>("boneWeights")
            .member<unsigned int>("vaoId")
            .member<unsigned int*>("vboId");

        world->component<Shader>()
            .member<unsigned int>("id")
            .member<int*>("locs");

        world->component<MaterialMap>()
            .member<Texture2D>("texture")
            .member<Color>("color")
            .member<float>("value");

        world->component<Material>()
            .member<Shader>("shader")
            .member<MaterialMap*>("maps")
            .member<float[4]>("params");

        world->component<Transform>()
            .member<Vector3>("translation")
            .member<Quaternion>("rotation")
            .member<Vector3>("scale");

        world->component<BoneInfo>()
            .member<char[32]>("name")
            .member<int>("parent");

        world->component<Model>()
            .member<Matrix>("transform")
            .member<int>("meshCount")
            .member<int>("materialCount")
            .member<Mesh*>("meshes")
            .member<Material*>("materials")
            .member<int*>("meshMaterial")
            .member<int>("boneCount")
            .member<BoneInfo*>("bones")
            .member<Transform*>("bindPose");

        world->component<ModelAnimation>()
            .member<int>("boneCount")
            .member<int>("frameCount")
            .member<BoneInfo*>("bones")
            .member<Transform**>("framePoses")
            .member<char[32]>("name");

        world->component<Ray>()
            .member<Vector3>("position")
            .member<Vector3>("direction");

        world->component<RayCollision>()
            .member<bool>("hit")
            .member<float>("distance")
            .member<Vector3>("point")
            .member<Vector3>("normal");

        world->component<BoundingBox>()
            .member<Vector3>("min")
            .member<Vector3>("max");

        world->component<Wave>()
            .member<unsigned int>("frameCount")
            .member<unsigned int>("sampleRate")
            .member<unsigned int>("sampleSize")
            .member<unsigned int>("channels")
            .member<void*>("data");

        world->component<AudioStream>()
            .member<rAudioBuffer*>("buffer")
            .member<rAudioProcessor*>("processor")
            .member<unsigned int>("sampleRate")
            .member<unsigned int>("sampleSize")
            .member<unsigned int>("channels");

        world->component<Sound>()
            .member<AudioStream>("stream")
            .member<unsigned int>("frameCount");

        world->component<Music>()
            .member<AudioStream>("stream")
            .member<unsigned int>("frameCount")
            .member<bool>("looping")
            .member<int>("ctxType")
            .member<void*>("ctxData");

        world->component<VrDeviceInfo>()
            .member<int>("hResolution")
            .member<int>("vResolution")
            .member<float>("hScreenSize")
            .member<float>("vScreenSize")
            .member<float>("eyeToScreenDistance")
            .member<float>("lensSeparationDistance")
            .member<float>("interpupillaryDistance")
            .member<float[4]>("lensDistortionValues")
            .member<float[4]>("chromaAbCorrection");

        world->component<VrStereoConfig>()
            .member<Matrix[2]>("projection")
            .member<Matrix[2]>("viewOffset")
            .member<float[2]>("leftLensCenter")
            .member<float[2]>("rightLensCenter")
            .member<float[2]>("leftScreenCenter")
            .member<float[2]>("rightScreenCenter")
            .member<float[2]>("scale")
            .member<float[2]>("scaleIn");

        world->component<FilePathList>()
            .member<unsigned int>("capacity")
            .member<unsigned int>("count")
            .member<char**>("paths");

        world->component<AutomationEvent>()
            .member<unsigned int>("frame")
            .member<unsigned int>("type")
            .member<int[4]>("params");

        world->component<AutomationEventList>()
            .member<unsigned int>("capacity")
            .member<unsigned int>("count")
            .member<AutomationEvent*>("events");
        
        // Enums
        world->component<ConfigFlags>()
            .constant("FLAG_VSYNC_HINT", FLAG_VSYNC_HINT)
            .constant("FLAG_FULLSCREEN_MODE", FLAG_FULLSCREEN_MODE)
            .constant("FLAG_WINDOW_RESIZABLE", FLAG_WINDOW_RESIZABLE)
            .constant("FLAG_WINDOW_UNDECORATED", FLAG_WINDOW_UNDECORATED)
            .constant("FLAG_WINDOW_HIDDEN", FLAG_WINDOW_HIDDEN)
            .constant("FLAG_WINDOW_MINIMIZED", FLAG_WINDOW_MINIMIZED)
            .constant("FLAG_WINDOW_MAXIMIZED", FLAG_WINDOW_MAXIMIZED)
            .constant("FLAG_WINDOW_UNFOCUSED", FLAG_WINDOW_UNFOCUSED)
            .constant("FLAG_WINDOW_TOPMOST", FLAG_WINDOW_TOPMOST)
            .constant("FLAG_WINDOW_ALWAYS_RUN", FLAG_WINDOW_ALWAYS_RUN)
            .constant("FLAG_WINDOW_TRANSPARENT", FLAG_WINDOW_TRANSPARENT)
            .constant("FLAG_WINDOW_HIGHDPI", FLAG_WINDOW_HIGHDPI)
            .constant("FLAG_WINDOW_MOUSE_PASSTHROUGH", FLAG_WINDOW_MOUSE_PASSTHROUGH)
            .constant("FLAG_BORDERLESS_WINDOWED_MODE", FLAG_BORDERLESS_WINDOWED_MODE)
            .constant("FLAG_MSAA_4X_HINT", FLAG_MSAA_4X_HINT)
            .constant("FLAG_INTERLACED_HINT", FLAG_INTERLACED_HINT);
        
        world->component<TraceLogLevel>()
            .constant("LOG_ALL", LOG_ALL)
            .constant("LOG_TRACE", LOG_TRACE)
            .constant("LOG_DEBUG", LOG_DEBUG)
            .constant("LOG_INFO", LOG_INFO)
            .constant("LOG_WARNING", LOG_WARNING)
            .constant("LOG_ERROR", LOG_ERROR)
            .constant("LOG_FATAL", LOG_FATAL)
            .constant("LOG_NONE", LOG_NONE);

        world->component<KeyboardKey>()
            .constant("KEY_VOLUME_DOWN", KEY_NULL)
            .constant("KEY_VOLUME_UP", KEY_APOSTROPHE)
            .constant("KEY_MENU", KEY_COMMA)
            .constant("KEY_BACK", KEY_MINUS)
            .constant("KEY_KP_EQUAL", KEY_PERIOD)
            .constant("KEY_KP_ENTER", KEY_SLASH)
            .constant("KEY_KP_ADD", KEY_ZERO)
            .constant("KEY_KP_SUBTRACT", KEY_ONE)
            .constant("KEY_KP_MULTIPLY", KEY_TWO)
            .constant("KEY_KP_DIVIDE", KEY_THREE)
            .constant("KEY_KP_DECIMAL", KEY_FOUR)
            .constant("KEY_KP_9", KEY_FIVE)
            .constant("KEY_KP_8", KEY_SIX)
            .constant("KEY_KP_7", KEY_SEVEN)
            .constant("KEY_KP_6", KEY_EIGHT)
            .constant("KEY_KP_5", KEY_NINE)
            .constant("KEY_KP_4", KEY_SEMICOLON)
            .constant("KEY_KP_3", KEY_EQUAL)
            .constant("KEY_KP_2", KEY_A)
            .constant("KEY_KP_1", KEY_B)
            .constant("KEY_KP_0", KEY_C)
            .constant("KEY_KB_MENU", KEY_D)
            .constant("KEY_RIGHT_SUPER", KEY_E)
            .constant("KEY_RIGHT_ALT", KEY_F)
            .constant("KEY_RIGHT_CONTROL", KEY_G)
            .constant("KEY_RIGHT_SHIFT", KEY_H)
            .constant("KEY_LEFT_SUPER", KEY_I)
            .constant("KEY_LEFT_ALT", KEY_J)
            .constant("KEY_LEFT_CONTROL", KEY_K)
            .constant("KEY_LEFT_SHIFT", KEY_L)
            .constant("KEY_F12", KEY_M)
            .constant("KEY_F11", KEY_N)
            .constant("KEY_F10", KEY_O)
            .constant("KEY_F9", KEY_P)
            .constant("KEY_F8", KEY_Q)
            .constant("KEY_F7", KEY_R)
            .constant("KEY_F6", KEY_S)
            .constant("KEY_F5", KEY_T)
            .constant("KEY_F4", KEY_U)
            .constant("KEY_F3", KEY_V)
            .constant("KEY_F2", KEY_W)
            .constant("KEY_F1", KEY_X)
            .constant("KEY_PAUSE", KEY_Y)
            .constant("KEY_PRINT_SCREEN", KEY_Z)
            .constant("KEY_NUM_LOCK", KEY_LEFT_BRACKET)
            .constant("KEY_SCROLL_LOCK", KEY_BACKSLASH)
            .constant("KEY_CAPS_LOCK", KEY_RIGHT_BRACKET)
            .constant("KEY_END", KEY_GRAVE)
            .constant("KEY_HOME", KEY_SPACE)
            .constant("KEY_PAGE_DOWN", KEY_ESCAPE)
            .constant("KEY_PAGE_UP", KEY_ENTER)
            .constant("KEY_UP", KEY_TAB)
            .constant("KEY_DOWN", KEY_BACKSPACE)
            .constant("KEY_LEFT", KEY_INSERT)
            .constant("KEY_RIGHT", KEY_DELETE)
            .constant("KEY_DELETE", KEY_RIGHT)
            .constant("KEY_INSERT", KEY_LEFT)
            .constant("KEY_BACKSPACE", KEY_DOWN)
            .constant("KEY_TAB", KEY_UP)
            .constant("KEY_ENTER", KEY_PAGE_UP)
            .constant("KEY_ESCAPE", KEY_PAGE_DOWN)
            .constant("KEY_SPACE", KEY_HOME)
            .constant("KEY_GRAVE", KEY_END)
            .constant("KEY_RIGHT_BRACKET", KEY_CAPS_LOCK)
            .constant("KEY_BACKSLASH", KEY_SCROLL_LOCK)
            .constant("KEY_LEFT_BRACKET", KEY_NUM_LOCK)
            .constant("KEY_Z", KEY_PRINT_SCREEN)
            .constant("KEY_Y", KEY_PAUSE)
            .constant("KEY_X", KEY_F1)
            .constant("KEY_W", KEY_F2)
            .constant("KEY_V", KEY_F3)
            .constant("KEY_U", KEY_F4)
            .constant("KEY_T", KEY_F5)
            .constant("KEY_S", KEY_F6)
            .constant("KEY_R", KEY_F7)
            .constant("KEY_Q", KEY_F8)
            .constant("KEY_P", KEY_F9)
            .constant("KEY_O", KEY_F10)
            .constant("KEY_N", KEY_F11)
            .constant("KEY_M", KEY_F12)
            .constant("KEY_L", KEY_LEFT_SHIFT)
            .constant("KEY_K", KEY_LEFT_CONTROL)
            .constant("KEY_J", KEY_LEFT_ALT)
            .constant("KEY_I", KEY_LEFT_SUPER)
            .constant("KEY_H", KEY_RIGHT_SHIFT)
            .constant("KEY_G", KEY_RIGHT_CONTROL)
            .constant("KEY_F", KEY_RIGHT_ALT)
            .constant("KEY_E", KEY_RIGHT_SUPER)
            .constant("KEY_D", KEY_KB_MENU)
            .constant("KEY_C", KEY_KP_0)
            .constant("KEY_B", KEY_KP_1)
            .constant("KEY_A", KEY_KP_2)
            .constant("KEY_EQUAL", KEY_KP_3)
            .constant("KEY_SEMICOLON", KEY_KP_4)
            .constant("KEY_NINE", KEY_KP_5)
            .constant("KEY_EIGHT", KEY_KP_6)
            .constant("KEY_SEVEN", KEY_KP_7)
            .constant("KEY_SIX", KEY_KP_8)
            .constant("KEY_FIVE", KEY_KP_9)
            .constant("KEY_FOUR", KEY_KP_DECIMAL)
            .constant("KEY_THREE", KEY_KP_DIVIDE)
            .constant("KEY_TWO", KEY_KP_MULTIPLY)
            .constant("KEY_ONE", KEY_KP_SUBTRACT)
            .constant("KEY_ZERO", KEY_KP_ADD)
            .constant("KEY_SLASH", KEY_KP_ENTER)
            .constant("KEY_PERIOD", KEY_KP_EQUAL)
            .constant("KEY_MINUS", KEY_BACK)
            .constant("KEY_COMMA", KEY_MENU)
            .constant("KEY_APOSTROPHE", KEY_VOLUME_UP)
            .constant("KEY_NULL", KEY_VOLUME_DOWN);
        
        world->component<MouseButton>()
            .constant("MOUSE_BUTTON_LEFT",MOUSE_BUTTON_LEFT)
            .constant("MOUSE_BUTTON_RIGHT",MOUSE_BUTTON_RIGHT)
            .constant("MOUSE_BUTTON_MIDDLE",MOUSE_BUTTON_MIDDLE)
            .constant("MOUSE_BUTTON_SIDE",MOUSE_BUTTON_SIDE)
            .constant("MOUSE_BUTTON_EXTRA",MOUSE_BUTTON_EXTRA)
            .constant("MOUSE_BUTTON_FORWAR",MOUSE_BUTTON_FORWARD)
            .constant("MOUSE_BUTTON_BACK",MOUSE_BUTTON_BACK);

        world->component<MouseCursor>()
            .constant("MOUSE_CURSOR_DEFAULT", MOUSE_CURSOR_DEFAULT)
            .constant("MOUSE_CURSOR_ARROW", MOUSE_CURSOR_ARROW)
            .constant("MOUSE_CURSOR_IBEAM", MOUSE_CURSOR_IBEAM)
            .constant("MOUSE_CURSOR_CROSSHAIR", MOUSE_CURSOR_CROSSHAIR)
            .constant("MOUSE_CURSOR_POINTING_HAND", MOUSE_CURSOR_POINTING_HAND)
            .constant("MOUSE_CURSOR_RESIZE_EW", MOUSE_CURSOR_RESIZE_EW)
            .constant("MOUSE_CURSOR_RESIZE_NS", MOUSE_CURSOR_RESIZE_NS)
            .constant("MOUSE_CURSOR_RESIZE_NWSE", MOUSE_CURSOR_RESIZE_NWSE)
            .constant("MOUSE_CURSOR_RESIZE_NESW", MOUSE_CURSOR_RESIZE_NESW)
            .constant("MOUSE_CURSOR_RESIZE_ALL", MOUSE_CURSOR_RESIZE_ALL)
            .constant("MOUSE_CURSOR_NOT_ALLOWED", MOUSE_CURSOR_NOT_ALLOWED);
        
        world->component<GamepadButton>()
            .constant("GAMEPAD_BUTTON_UNKNOWN", GAMEPAD_BUTTON_UNKNOWN)
            .constant("GAMEPAD_BUTTON_LEFT_FACE_UP", GAMEPAD_BUTTON_LEFT_FACE_UP)
            .constant("GAMEPAD_BUTTON_LEFT_FACE_RIGHT", GAMEPAD_BUTTON_LEFT_FACE_RIGHT)
            .constant("GAMEPAD_BUTTON_LEFT_FACE_DOWN", GAMEPAD_BUTTON_LEFT_FACE_DOWN)
            .constant("GAMEPAD_BUTTON_LEFT_FACE_LEFT", GAMEPAD_BUTTON_LEFT_FACE_LEFT)
            .constant("GAMEPAD_BUTTON_RIGHT_FACE_UP", GAMEPAD_BUTTON_RIGHT_FACE_UP)
            .constant("GAMEPAD_BUTTON_RIGHT_FACE_RIGHT", GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)
            .constant("GAMEPAD_BUTTON_RIGHT_FACE_DOWN", GAMEPAD_BUTTON_RIGHT_FACE_DOWN)
            .constant("GAMEPAD_BUTTON_RIGHT_FACE_LEFT", GAMEPAD_BUTTON_RIGHT_FACE_LEFT)
            .constant("GAMEPAD_BUTTON_LEFT_TRIGGER_1", GAMEPAD_BUTTON_LEFT_TRIGGER_1)
            .constant("GAMEPAD_BUTTON_LEFT_TRIGGER_2", GAMEPAD_BUTTON_LEFT_TRIGGER_2)
            .constant("GAMEPAD_BUTTON_RIGHT_TRIGGER_1", GAMEPAD_BUTTON_RIGHT_TRIGGER_1)
            .constant("GAMEPAD_BUTTON_RIGHT_TRIGGER_2", GAMEPAD_BUTTON_RIGHT_TRIGGER_2)
            .constant("GAMEPAD_BUTTON_MIDDLE_LEFT", GAMEPAD_BUTTON_MIDDLE_LEFT)
            .constant("GAMEPAD_BUTTON_MIDDLE", GAMEPAD_BUTTON_MIDDLE)
            .constant("GAMEPAD_BUTTON_MIDDLE_RIGHT", GAMEPAD_BUTTON_MIDDLE_RIGHT)
            .constant("GAMEPAD_BUTTON_LEFT_THUMB", GAMEPAD_BUTTON_LEFT_THUMB)
            .constant("GAMEPAD_BUTTON_RIGHT_THUMB", GAMEPAD_BUTTON_RIGHT_THUMB);
        
        world->component<GamepadAxis>()
            .constant("GAMEPAD_AXIS_LEFT_X", GAMEPAD_AXIS_LEFT_X)
            .constant("GAMEPAD_AXIS_LEFT_Y", GAMEPAD_AXIS_LEFT_Y)
            .constant("GAMEPAD_AXIS_RIGHT_X", GAMEPAD_AXIS_RIGHT_X)
            .constant("GAMEPAD_AXIS_RIGHT_Y", GAMEPAD_AXIS_RIGHT_Y)
            .constant("GAMEPAD_AXIS_LEFT_TRIGGER ", GAMEPAD_AXIS_LEFT_TRIGGER)
            .constant("GAMEPAD_AXIS_RIGHT_TRIGGER", GAMEPAD_AXIS_RIGHT_TRIGGER);
        
        world->component<MaterialMapIndex>()
            .constant("MATERIAL_MAP_ALBEDO", MATERIAL_MAP_ALBEDO)
            .constant("MATERIAL_MAP_METALNESS", MATERIAL_MAP_METALNESS)
            .constant("MATERIAL_MAP_NORMAL", MATERIAL_MAP_NORMAL)
            .constant("MATERIAL_MAP_ROUGHNESS", MATERIAL_MAP_ROUGHNESS)
            .constant("MATERIAL_MAP_OCCLUSION", MATERIAL_MAP_OCCLUSION)
            .constant("MATERIAL_MAP_EMISSION", MATERIAL_MAP_EMISSION)
            .constant("MATERIAL_MAP_HEIGHT", MATERIAL_MAP_HEIGHT)
            .constant("MATERIAL_MAP_CUBEMAP", MATERIAL_MAP_CUBEMAP)
            .constant("MATERIAL_MAP_IRRADIANCE", MATERIAL_MAP_IRRADIANCE)
            .constant("MATERIAL_MAP_PREFILTER", MATERIAL_MAP_PREFILTER)
            .constant("MATERIAL_MAP_BRDF", MATERIAL_MAP_BRDF);
        
        world->component<ShaderLocationIndex>()
            .constant("SHADER_LOC_VERTEX_POSITION", SHADER_LOC_VERTEX_POSITION)
            .constant("SHADER_LOC_VERTEX_TEXCOORD01", SHADER_LOC_VERTEX_TEXCOORD01)
            .constant("SHADER_LOC_VERTEX_TEXCOORD02", SHADER_LOC_VERTEX_TEXCOORD02)
            .constant("SHADER_LOC_VERTEX_NORMAL", SHADER_LOC_VERTEX_NORMAL)
            .constant("SHADER_LOC_VERTEX_TANGENT", SHADER_LOC_VERTEX_TANGENT)
            .constant("SHADER_LOC_VERTEX_COLOR", SHADER_LOC_VERTEX_COLOR)
            .constant("SHADER_LOC_MATRIX_MVP", SHADER_LOC_MATRIX_MVP)
            .constant("SHADER_LOC_MATRIX_VIEW", SHADER_LOC_MATRIX_VIEW)
            .constant("SHADER_LOC_MATRIX_PROJECTION", SHADER_LOC_MATRIX_PROJECTION)
            .constant("SHADER_LOC_MATRIX_MODEL", SHADER_LOC_MATRIX_MODEL)
            .constant("SHADER_LOC_MATRIX_NORMAL", SHADER_LOC_MATRIX_NORMAL)
            .constant("SHADER_LOC_VECTOR_VIEW", SHADER_LOC_VECTOR_VIEW)
            .constant("SHADER_LOC_COLOR_DIFFUSE", SHADER_LOC_COLOR_DIFFUSE)
            .constant("SHADER_LOC_COLOR_SPECULAR", SHADER_LOC_COLOR_SPECULAR)
            .constant("SHADER_LOC_COLOR_AMBIENT", SHADER_LOC_COLOR_AMBIENT)
            .constant("SHADER_LOC_MAP_ALBEDO", SHADER_LOC_MAP_ALBEDO)
            .constant("SHADER_LOC_MAP_METALNESS", SHADER_LOC_MAP_METALNESS)
            .constant("SHADER_LOC_MAP_NORMAL", SHADER_LOC_MAP_NORMAL)
            .constant("SHADER_LOC_MAP_ROUGHNESS", SHADER_LOC_MAP_ROUGHNESS)
            .constant("SHADER_LOC_MAP_OCCLUSION", SHADER_LOC_MAP_OCCLUSION)
            .constant("SHADER_LOC_MAP_EMISSION", SHADER_LOC_MAP_EMISSION)
            .constant("SHADER_LOC_MAP_HEIGHT", SHADER_LOC_MAP_HEIGHT)
            .constant("SHADER_LOC_MAP_CUBEMAP", SHADER_LOC_MAP_CUBEMAP)
            .constant("SHADER_LOC_MAP_IRRADIANCE", SHADER_LOC_MAP_IRRADIANCE)
            .constant("SHADER_LOC_MAP_PREFILTER", SHADER_LOC_MAP_PREFILTER)
            .constant("SHADER_LOC_MAP_BRDF", SHADER_LOC_MAP_BRDF);
        
        world->component<ShaderUniformDataType>()
            .constant("SHADER_UNIFORM_FLOAT", SHADER_UNIFORM_FLOAT)
            .constant("SHADER_UNIFORM_VEC2", SHADER_UNIFORM_VEC2)
            .constant("SHADER_UNIFORM_VEC3", SHADER_UNIFORM_VEC3)
            .constant("SHADER_UNIFORM_VEC4", SHADER_UNIFORM_VEC4)
            .constant("SHADER_UNIFORM_INT", SHADER_UNIFORM_INT)
            .constant("SHADER_UNIFORM_IVEC2", SHADER_UNIFORM_IVEC2)
            .constant("SHADER_UNIFORM_IVEC3", SHADER_UNIFORM_IVEC3)
            .constant("SHADER_UNIFORM_IVEC4", SHADER_UNIFORM_IVEC4)
            .constant("SHADER_UNIFORM_SAMPLER2D", SHADER_UNIFORM_SAMPLER2D);
        
        world->component<ShaderAttributeDataType>()
            .constant("SHADER_ATTRIB_FLOAT", SHADER_ATTRIB_FLOAT)
            .constant("SHADER_ATTRIB_VEC2", SHADER_ATTRIB_VEC2)
            .constant("SHADER_ATTRIB_VEC3", SHADER_ATTRIB_VEC3)
            .constant("SHADER_ATTRIB_VEC4", SHADER_ATTRIB_VEC4);
        
        world->component<PixelFormat>()
            .constant("PIXELFORMAT_UNCOMPRESSED_GRAYSCALE", PIXELFORMAT_UNCOMPRESSED_GRAYSCALE)
            .constant("PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA", PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA)
            .constant("PIXELFORMAT_UNCOMPRESSED_R5G6B5", PIXELFORMAT_UNCOMPRESSED_R5G6B5)
            .constant("PIXELFORMAT_UNCOMPRESSED_R8G8B8", PIXELFORMAT_UNCOMPRESSED_R8G8B8)
            .constant("PIXELFORMAT_UNCOMPRESSED_R5G5B5A1", PIXELFORMAT_UNCOMPRESSED_R5G5B5A1)
            .constant("PIXELFORMAT_UNCOMPRESSED_R4G4B4A4", PIXELFORMAT_UNCOMPRESSED_R4G4B4A4)
            .constant("PIXELFORMAT_UNCOMPRESSED_R8G8B8A8", PIXELFORMAT_UNCOMPRESSED_R8G8B8A8)
            .constant("PIXELFORMAT_UNCOMPRESSED_R32", PIXELFORMAT_UNCOMPRESSED_R32)
            .constant("PIXELFORMAT_UNCOMPRESSED_R32G32B32", PIXELFORMAT_UNCOMPRESSED_R32G32B32)
            .constant("PIXELFORMAT_UNCOMPRESSED_R32G32B32A32", PIXELFORMAT_UNCOMPRESSED_R32G32B32A32)
            .constant("PIXELFORMAT_UNCOMPRESSED_R16", PIXELFORMAT_UNCOMPRESSED_R16)
            .constant("PIXELFORMAT_UNCOMPRESSED_R16G16B16", PIXELFORMAT_UNCOMPRESSED_R16G16B16)
            .constant("PIXELFORMAT_UNCOMPRESSED_R16G16B16A16", PIXELFORMAT_UNCOMPRESSED_R16G16B16A16)
            .constant("PIXELFORMAT_COMPRESSED_DXT1_RGB", PIXELFORMAT_COMPRESSED_DXT1_RGB)
            .constant("PIXELFORMAT_COMPRESSED_DXT1_RGBA", PIXELFORMAT_COMPRESSED_DXT1_RGBA)
            .constant("PIXELFORMAT_COMPRESSED_DXT3_RGBA", PIXELFORMAT_COMPRESSED_DXT3_RGBA)
            .constant("PIXELFORMAT_COMPRESSED_DXT5_RGBA", PIXELFORMAT_COMPRESSED_DXT5_RGBA)
            .constant("PIXELFORMAT_COMPRESSED_ETC1_RGB", PIXELFORMAT_COMPRESSED_ETC1_RGB)
            .constant("PIXELFORMAT_COMPRESSED_ETC2_RGB", PIXELFORMAT_COMPRESSED_ETC2_RGB)
            .constant("PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA", PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA)
            .constant("PIXELFORMAT_COMPRESSED_PVRT_RGB", PIXELFORMAT_COMPRESSED_PVRT_RGB)
            .constant("PIXELFORMAT_COMPRESSED_PVRT_RGBA", PIXELFORMAT_COMPRESSED_PVRT_RGBA)
            .constant("PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA", PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA)
            .constant("PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA", PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA);
        
        world->component<TextureFilter>()
            .constant("TEXTURE_FILTER_POINT", TEXTURE_FILTER_POINT)
            .constant("TEXTURE_FILTER_BILINEAR", TEXTURE_FILTER_BILINEAR)
            .constant("TEXTURE_FILTER_TRILINEAR", TEXTURE_FILTER_TRILINEAR)
            .constant("TEXTURE_FILTER_ANISOTROPIC_4X", TEXTURE_FILTER_ANISOTROPIC_4X)
            .constant("TEXTURE_FILTER_ANISOTROPIC_8X", TEXTURE_FILTER_ANISOTROPIC_8X)
            .constant("TEXTURE_FILTER_ANISOTROPIC_16X", TEXTURE_FILTER_ANISOTROPIC_16X);
        
        world->component<TextureWrap>()
            .constant("TEXTURE_WRAP_REPEAT", TEXTURE_WRAP_REPEAT)
            .constant("TEXTURE_WRAP_CLAMP", TEXTURE_WRAP_CLAMP)
            .constant("TEXTURE_WRAP_MIRROR_REPEAT", TEXTURE_WRAP_MIRROR_REPEAT)
            .constant("TEXTURE_WRAP_MIRROR_CLAMP", TEXTURE_WRAP_MIRROR_CLAMP);
        
        world->component<CubemapLayout>()
            .constant("CUBEMAP_LAYOUT_AUTO_DETECT", CUBEMAP_LAYOUT_AUTO_DETECT)
            .constant("CUBEMAP_LAYOUT_LINE_VERTICAL", CUBEMAP_LAYOUT_LINE_VERTICAL)
            .constant("CUBEMAP_LAYOUT_LINE_HORIZONTAL", CUBEMAP_LAYOUT_LINE_HORIZONTAL)
            .constant("CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR", CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR)
            .constant("CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE", CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE)
            .constant("CUBEMAP_LAYOUT_PANORAMA", CUBEMAP_LAYOUT_PANORAMA);
        
        world->component<FontType>()
            .constant("FONT_DEFAULT", FONT_DEFAULT)
            .constant("FONT_BITMAP", FONT_BITMAP)
            .constant("FONT_SDF", FONT_SDF);

        world->component<BlendMode>()
            .constant("BLEND_ALPHA", BLEND_ALPHA)
            .constant("BLEND_ADDITIVE", BLEND_ADDITIVE)
            .constant("BLEND_MULTIPLIED", BLEND_MULTIPLIED)
            .constant("BLEND_ADD_COLORS", BLEND_ADD_COLORS)
            .constant("BLEND_SUBTRACT_COLORS", BLEND_SUBTRACT_COLORS)
            .constant("BLEND_ALPHA_PREMULTIPLY", BLEND_ALPHA_PREMULTIPLY)
            .constant("BLEND_CUSTOM", BLEND_CUSTOM)
            .constant("BLEND_CUSTOM_SEPARATE", BLEND_CUSTOM_SEPARATE);
        
        world->component<Gesture>()
            .constant("GESTURE_NONE", GESTURE_NONE)
            .constant("GESTURE_TAP", GESTURE_TAP)
            .constant("GESTURE_DOUBLETAP", GESTURE_DOUBLETAP)
            .constant("GESTURE_HOLD", GESTURE_HOLD)
            .constant("GESTURE_DRAG", GESTURE_DRAG)
            .constant("GESTURE_SWIPE_RIGHT", GESTURE_SWIPE_RIGHT)
            .constant("GESTURE_SWIPE_LEFT", GESTURE_SWIPE_LEFT)
            .constant("GESTURE_SWIPE_UP", GESTURE_SWIPE_UP)
            .constant("GESTURE_SWIPE_DOWN", GESTURE_SWIPE_DOWN)
            .constant("GESTURE_PINCH_IN", GESTURE_PINCH_IN)
            .constant("GESTURE_PINCH_OUT", GESTURE_PINCH_OUT);
        
        world->component<CameraMode>()
            .constant("CAMERA_CUSTOM", CAMERA_CUSTOM)
            .constant("CAMERA_FREE", CAMERA_FREE)
            .constant("CAMERA_ORBITAL", CAMERA_ORBITAL)
            .constant("CAMERA_FIRST_PERSON", CAMERA_FIRST_PERSON)
            .constant("CAMERA_THIRD_PERSON", CAMERA_THIRD_PERSON);
        
        world->component<CameraProjection>()
            .constant("CAMERA_PERSPECTIVE", CAMERA_PERSPECTIVE)
            .constant("CAMERA_ORTHOGRAPHIC", CAMERA_ORTHOGRAPHIC);
        
        world->component<NPatchLayout>()
            .constant("NPATCH_NINE_PATCH", NPATCH_NINE_PATCH)
            .constant("NPATCH_THREE_PATCH_VERTICAL", NPATCH_THREE_PATCH_VERTICAL)
            .constant("NPATCH_THREE_PATCH_HORIZONTAL", NPATCH_THREE_PATCH_HORIZONTAL);
    }
}