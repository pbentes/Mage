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

---@return nil
function Behaviour:start()
end

---@param delta number?
---@return nil
function Behaviour:update(delta)
end

---@param delta number?
---@return nil
function Behaviour:late_update(delta)
end

---@return nil
function Behaviour:on_destroy()
end

---@return nil
function Behaviour:on_enable()
end

---@return nil
function Behaviour:on_disable()
end

-- Physics Hooks

---@param delta number?
---@return nil
function Behaviour:fixed_update(delta)
end

---@return nil
function Behaviour:on_trigger_enter()
end

---@return nil
function Behaviour:on_trigger_stay()
end

---@return nil
function Behaviour:on_trigger_exit()
end

---@return nil
function Behaviour:on_collision_enter()
end

---@return nil
function Behaviour:on_collision_stay()
end

---@return nil
function Behaviour:on_collision_exit()
end

-- Rendering hooks

---@return nil
function Behaviour:on_draw_gizmos()
end

---@return nil
function Behaviour:on_gui()
end

Behaviour.__index = Behaviour