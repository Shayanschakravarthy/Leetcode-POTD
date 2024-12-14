class Solution:
    def pickGifts(self, gifts: List[int], z: int) -> int:
        h = [-v for v in gifts]
        heapify(h)
        for _ in range(z):
            heapreplace(h, -int(sqrt(-h[0])))
        return -sum(h)
