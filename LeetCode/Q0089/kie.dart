class Solution {
  List<int> grayCode(int n) {
    if (n == 0) {
      var list = List<int>.empty(growable: true);
      list.add(0);
      return list;
    }

    var list = grayCode(n - 1);
    for (var i = list.length - 1; i >= 0; i--) {
      list.add(list[i] | 1 << n - 1);
    }

    return list;
  }
}

void main(List<String> arguments) {
  print(Solution().grayCode(3).map((e) => e.toRadixString(2)));
}
