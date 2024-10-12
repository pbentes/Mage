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

---Runs once when the script starts up
---@return nil
function Behaviour:start()
end

---Runs at the start of every frame
---@param delta number?
---@return nil
function Behaviour:update(delta)
end

---Runs at the end of every frame
---@param delta number?
---@return nil
function Behaviour:late_update(delta)
end

---Runs when the component or entity is destroyed
---@return nil
function Behaviour:on_destroy()
end

---Runs when the component is enabled
---@return nil
function Behaviour:on_enable()
end

---Runs when the coponent is disabled
---@return nil
function Behaviour:on_disable()
end

-- Physics Hooks

---Runs every physics frame
---@param delta number?
---@return nil
function Behaviour:fixed_update(delta)
end

---Runs when entering a trigger
---@return nil
function Behaviour:on_trigger_enter()
end

---Runs when on a trigger for more than one frame
---@return nil
function Behaviour:on_trigger_stay()
end

---Runs when exiting a trigger
---@return nil
function Behaviour:on_trigger_exit()
end

---Runs when entering a collision
---@return nil
function Behaviour:on_collision_enter()
end

---Runs when on a collision for more than one frame
---@return nil
function Behaviour:on_collision_stay()
end

---Runs when exiting a collision
---@return nil
function Behaviour:on_collision_exit()
end

-- Rendering hooks

---Runs when drawing guizmos
---@return nil
function Behaviour:on_draw_gizmos()
end

---Runs when drawing Gui
---@return nil
function Behaviour:on_gui()
end

Behaviour.__index = Behaviour