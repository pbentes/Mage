Settings = {
    --- @type table
    config = {
        --- @type string
        name = "",

        --- @type table
        name_localized = {},

        --- @type string
        version = "",

        --- @type string
        icon = ""
    },

    --- @type table
    run = {
        --- @type string
        main_scene = ""
    },

    --- @type table
    audio = {
        --- @type string
        default_audio_bus = ""
    },

    --- @type table
    physics = {
        --- @type table
        common = {
            --- @type integer
            physics_ticks_per_second = 60,

            --- @type integer
            max_physics_steps_per_frame = 8
        },

        --- @type table
        _3d = {
            --- @type number
            default_gravity = 9.8,

            --- @type Vector3
            default_gravity_vector = Vector3.Down
        },

        --- @type table
        _2d = {
            --- @type number
            default_gravity = 980,

            --- @type Vector2
            default_gravity_vector = Vector2.Up
        }
    }
}

---Get a the value related to a given key
--- @param key string
--- @return (string | number | integer)
function Settings:get(key)
    return self:get(key)
end