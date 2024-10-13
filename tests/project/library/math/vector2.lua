-- Placeholder for LuaLS code completion

--- @class Vector2
--- @field x number
--- @field y number
Vector2 = {
    Zero = Vector2:new(0, 0),
    Up = Vector2:new(0, 1),
    Down = Vector2:new(0, -1),
    Right = Vector2:new(1, 0),
    Left = Vector2:new(-1, 0)
}

--- @param x number
--- @param y number
--- @return Vector2
function Vector2:new(x, y)
    local obj = {}
    setmetatable(obj, self)
    self.__index = self

    obj.x = x
    obj.y = y

    return obj
end