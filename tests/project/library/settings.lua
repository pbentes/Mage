Settings = {
    config = {
        name = "",
        name_localized = {},
        version = "",
        icon = ""
    },
    gravity = 9.8,
    run = {
        main_scene = ""
    },
    audio = {
        default_audio_bus = ""
    },
    physics = {
        common = {
            physics_ticks_per_second = 60,
            max_physics_steps_per_frame = 8
        },
        _3d = {
            default_gravity = 9.8,
            default_gravity_vector = { x = 0, y = -1, z = 0 }
        },
        _2d = {
            default_gravity = 980,
            default_gravity_vector = { x = 0, y = 1 }
        }
    }
}

---Get a the value related to a given key
---@param key string
---@return (string | number)
function Settings:get(key)
    return self:get(key)
end