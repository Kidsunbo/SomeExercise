class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        # # Shorter, but slower
        # pair = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        # for k,v in pair.items():
        #     if num>=v:
        #         return k+self.intToRoman(num-v)
        # return ""

        if num>=1000:
            return "M"+self.intToRoman(num-1000)
        elif num>=900:
            return "CM"+self.intToRoman(num-900)
        elif num>=500:
            return "D"+self.intToRoman(num-500)
        elif num>=400:
            return "CD"+self.intToRoman(num-400)
        elif num>=100:
            return "C"+self.intToRoman(num-100)
        elif num>=90:
            return "XC"+self.intToRoman(num-90)
        elif num>=50:
            return "L"+self.intToRoman(num-50)
        elif num>=40:
            return "XL"+self.intToRoman(num-40)
        elif num>=10:
            return "X"+self.intToRoman(num-10)
        elif num>=9:
            return "IX"+self.intToRoman(num-9)
        elif num>=5:
            return "V"+self.intToRoman(num-5)
        elif num>=4:
            return "IV"+self.intToRoman(num-4)
        elif num>=1:
            return "I"+self.intToRoman(num-1)
        else:
            return ""


if __name__ == '__main__':
    s = Solution()
    print(s.intToRoman(499))