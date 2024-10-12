---@class Player: Behaviour
Player = Behaviour:new()

local k = 120

---@type number
Player.j = 10

function Player:update(delta)
    if delta ~= nil then
        self.k = k + delta
    end
    self.j = self.j + 1
end