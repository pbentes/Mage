---@class Behaviour
---@field class string
Behaviour = {
    class = "Behaviour"
}

-- Constructor

function Behaviour:new ()
    local obj = {}
    setmetatable(obj, self)
    self.__index = self
    return obj
end

-- Lifecycle Hooks

function Behaviour:start()
end

function Behaviour:update()
end

function Behaviour:late_update()
end

function Behaviour:on_destroy()
end

function Behaviour:on_enable()
end

function Behaviour:on_disable()
end

-- Physics Hooks

function Behaviour:fixed_update()
end

function Behaviour:on_trigger_enter()
end

function Behaviour:on_trigger_stay()
end

function Behaviour:on_trigger_exit()
end

function Behaviour:on_collision_enter()
end

function Behaviour:on_collision_stay()
end

function Behaviour:on_collision_exit()
end

-- Rendering hooks

function Behaviour:on_draw_gizmos()
end

function Behaviour:on_gui()
end

Behaviour.__index = Behaviour