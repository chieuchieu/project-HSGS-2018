# Chuyển đổi ký tự

#### 1 byte (hoặc 8 bit) được sử dụng để biểu diễn một ký hiệu chữ cái (ký tự) trong máy tính.
#### Một bảng mã có tác dụng quy định mã (biểu diễn nhị phân) của mỗi ký hiệu.
#### Công việc của bạn là viết một chương trình biến đổi chữ từ bảng mã A sang bảng mã B.

## Đặc tả dữ liệu đầu vào
__Dữ liệu đầu vào gồm 3 file: `A.TBL`, `B.TBL`, `A.T`.__



Bạn sẽ tìm thấy bảng mã A trong file `A.TBL` và bảng mã B trong file `B.TBL`.

Mỗi file chứa 128 dòng; mỗi dòng được gán cho một ký hiệu.
Thông thường một bảng mã 8-bit sẽ chứa 256 ký hiệu, tuy nhiên chúng ta có thể chắc chắn rằng 128 ký hiệu đầu tiên sẽ có mã giống nhau trong mọi bảng mã, do đó mã của chúng không được cho trước trong file.

Dưới đây là một phần của file chứa bảng mã 1257, được dùng ở các nước vùng Baltic: 

```
0x80        #UNDEFINED
0x81        #UNDEFINED
0x82 0x201A #LOW SINGLE COMMA QUOTATION MARK
...
0xC6 0x0118 #LATIN CAPITAL E OGONEK
0xC7 0x0112 #LATIN CAPITAL E MACRON
0xC8 0x010C #LATIN CAPITAL C HACEK
0xC9 0x00C9 #LATIN CAPITAL E ACUTE
0xCA 0x0179 #LATIN CAPITAL Z ACUTE
0xCB 0x0116 #LATIN CAPITAL E DOT ABOVE
...
0xFE 0x017E #LATIN SMALL Z HACEK
0xFF 0x02D9 #DOT ABOVE
```

Mỗi dòng có cấu trúc như sau:
###### _Vị trí 1 - 4_ :  Mã thập lục phân của ký hiệu. 2 ký tự đầu tiên, `0x`, biểu thị đây là số viết trong hệ thập lục phân; 2 ký tự sau chính là mã của ký hiệu.
###### _Vị trí 5_ : Khoẳng trắng.
###### _Vị trí 6 - 11_ : Mã thập lục phân của ký hiệu trong bảng mã Unicode.
###### _Vị trí 12_ : Khoẳng trắng.
###### _Vị trí 13 trở đi_ : Chú thích - mô tả của ký hiệu.
__Phần chú thích có thể được bỏ qua.__

Mỗi ký hiệu đều có thể được nhận dạng qua mã của nó trong bảng mã Unicode. Một ký hiệu nhất định sẽ luôn luôn có cùng mã Unicode trong mọi bảng mã.
Các chữ số thập lục phân (`A`, `B`, `C`, `D`, `E`, `F`) được viết hoa.
Các dòng của bảng mã được sắp xếp tăng dần theo mã 8-bit của ký hiệu.

Trong trường hợp một mã không được dùng trong một bảng mã Z nào đó, mã đó vẫn sẽ được ghi trong Z; tuy nhiên, các khoảng trắng được thay cho mã Unicode và chú thích của mã đó sẽ là `#UNDEFINED`, như ví dụ sau:
```
0x81        #UNDEFINED
```

Các ký hiệu để chuyển đổi được cho trong file `A.T` và được viết với bảng mã A.
`A.T` không chứa bất kỳ ký hiệu nào được đánh dấu là `#UNDEFINED` trong `A.TBL`.

Số dòng trong file `A.T` luôn là số nguyên dương không lớn hơn 1000.
Mỗi dòng chứa nhiều nhất là 80 ký hiệu. Có thể tồn tại dòng trống.


## Đặc tả dữ liệu đầu ra
Nội dung trong file `A.T`, được chuyển đổi sang bảng mã B - viết vào file `B.T`.

Nếu một ký hiệu được xác định là không tồn tại trong bảng mã B, viết ký hiệu `#` thay thế.

Cấu trúc của `A.T` và `B.T` phải giống nhau hoàn toàn. Tức là:
- Số dòng trong 2 file là bằng nhau
- Số ký tự trên các dòng tương ứng trong 2 file là bằng nhau

<sup><sub>dịch bởi [cipher::allies](https://github.com/minhducsun2002)</sub></sup>
