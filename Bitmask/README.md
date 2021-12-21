### set,get
Check if the i^{th} bit of a binary number is set to 1: x & (1 << i).

Set the i^{th} bit of a binary number x to 1: x = x | (1 << i)

### Only keep the rightmost bit (e.g. 231) 
x and -x have just one bit in common - the rightmost 1-bit. That means that x & (-x) would keep that rightmost 1-bit and set all the other bits to 0.

![avatar](rightmost.png)
