TestBehaviour = {
    j = 10,
}

function TestBehaviour:update (delta)
    self.j = self.j + 1
end

return TestBehaviour