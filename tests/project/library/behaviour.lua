---@class Behaviour
---@field class string
Behaviour = {
    class = "Behaviour"
}

function Behaviour:new ()
    local obj = {}
    setmetatable(obj, self)
    self.__index = self
    return obj
end

Behaviour.__index = Behaviour