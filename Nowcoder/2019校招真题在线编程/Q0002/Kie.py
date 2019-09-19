def main():
    low,high = map(int,input().split())
    count = (high-low+1)//3*2
    if (high-low+1)%3!=0: count+=(high-1)%3
    print(count)

if __name__ == '__main__':
    main()