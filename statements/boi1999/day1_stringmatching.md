# GHÉP CHUỖI

#### Bạn được cho hai tập hợp xâu, tạm gọi là tập hợp A và tập hợp B.
#### Gọi xâu S là một xâu thoả mãn toàn bộ những điều kiện sau:
- Có thể ghép được xâu S từ một hoặc nhiều xâu thuộc A.
- Có thể ghép được xâu S từ một hoặc nhiều xâu thuộc B.

Công việc của bạn là tìm ra sự tồn tại của xâu S như trên. Nếu tồn tại nhiều xâu thoả mãn, bạn cần tìm xâu ngắn nhất.

__Chú ý: Một xâu có thể được lặp lại nhiều lần khi ghép.__

## Đặc tả dữ liệu đầu vào
__Các dữ liệu đầu vào được nhập từ file__ `MATCH.IN`.
Dòng đầu tiên của file chứa một số nguyên `N` - giới hạn:`(0 ≤ N ≤ 100)` - biểu thị số xâu trong tập hợp A.
`N` dòng sau đó chứa các chuỗi thuộc tập hợp A, mỗi chuỗi trên một dòng.

Dòng đầu tiên của file chứa một số nguyên `M` - giới hạn:`(0 ≤ M ≤ 100)` - biểu thị số xâu trong tập hợp B.
`M` dòng sau đó chứa các chuỗi thuộc tập hợp A, mỗi chuỗi trên một dòng.
__Tất cả các chuỗi đều sử dụng chữ hoa Latin và có độ dài nằm trong khoảng từ 1 đến 50.__

## Đặc tả dữ liệu đầu ra
__(Các) dữ liệu đầu ra được ghi vào file `MATCH.OUT`.__
Nếu không tồn tại xâu S thoả mãn, chương trình bắt buộc phải viết `0` trên dòng đầu tiên và duy nhất của file. 

Nếu tồn tại xâu S thoả mãn, dòng đâu tiên của file chứa độ dài của xâu S ngắn nhất có thể. Dòng kế tiếp chứa biểu diễn của S dưới dạng ghép nối các xâu từ tập hợp A, phân cách nhau bởi dấu `+`. Dòng cuối chứa biểu diễn của S dưới dạng ghép nối các xâu từ tập hợp B, phân cách nhau bởi dấu `+`.

__Nếu tồn tại nhiều xâu S thoả mãn, in ra biểu diễn của một xâu S bất kỳ. Nếu tồn tại nhiều cách biểu diễn khác nhau của xâu S từ cùng một tập hợp, in ra biểu diễn bất kỳ.__

## Các ví dụ
##### Ví dụ 1:
###### Dữ liệu đầu vào (file `MATCH.IN`):
```
1
AB
2
A
BA
```
###### Dữ liệu đầu ra (file `MATCH.OUT`):
```
0
```

##### Ví dụ 2:
###### Dữ liệu đầu vào (file `MATCH.IN`):
```
2
ABC
CB
2
CBA
BC
```
###### Dữ liệu đầu ra (file `MATCH.OUT`):
```
5
CB+ABC
CBA+BC
```
