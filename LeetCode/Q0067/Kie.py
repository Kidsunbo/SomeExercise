# # Time:45.24%  Memory:5.41%
# class Solution:
#     def addBinary(self, a: str, b: str) -> str:
#         carry = 0
#         result = []
#         i = len(a) - 1
#         j = len(b) - 1
#         while i >= 0 and j >= 0:
#             result.append(str((int(a[i]) + int(b[j]) + carry) % 2))
#             carry = (int(a[i]) + int(b[j]) + carry) // 2
#             i -= 1
#             j -= 1
#         if i>=0:
#             while i>=0:
#                 result.append(str((int(a[i])+carry)%2))
#                 carry = (int(a[i])+carry)//2
#                 i-=1
#         elif j>=0:
#             while j>=0:
#                 result.append(str((int(b[j]) + carry) % 2))
#                 carry = (int(b[j]) + carry) // 2
#                 j -= 1
#         if carry==1:
#             result.append(str(carry))
#         result.reverse()
#         return "".join(result)

# Time:97.96%  Memory: 5.41%
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = int(a,2)
        b = int(b,2)
        return str(bin(a+b)[2:])

if __name__ == '__main__':
    s = Solution()
    print(s.addBinary("10101", "10110"))
