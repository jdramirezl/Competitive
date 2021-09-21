class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        while n > 0 and m > 0:
            if nums2[n - 1] > nums1[m - 1]:
                nums1[n + m - 1] = nums2[n - 1]
                n -= 1
            else:
                nums1[n + m - 1] = nums1[m - 1]
                m -= 1
        if n > 0:
            nums1[:n] = nums2[:n]