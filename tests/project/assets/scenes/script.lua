---@class Player: Behaviour
Player = Behaviour:new()

local k = 120

---@type number
Player.j = 10

function Player:update(delta)
    ---@type Player
    local player1 = Entity1_Player
    print("Player1:", player1.j)
    k = k + 1

    self.j = self.j + 1
    print(self.j)
end