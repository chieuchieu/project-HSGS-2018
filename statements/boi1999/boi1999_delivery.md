# Giao hàng

##### Có một khối lượng lớn gói hàng cần được chuyển trong một giới hạn thời gian nhất định.
##### Có hai phương tiện có sẵn cho việc trung chuyển:  xe thùng và xe tải. Do ngân sách hạn hẹp, bạn chỉ có một chiếc mỗi loại.
##### Một gói hàng có thể là cỡ lớn hoặc cỡ nhỏ. Một gói hàng nhỏ có thể được vận chuyển bằng bất kỳ loại xe nào, nhưng vận chuyển một gói hàng lớn sẽ yêu cầu sử dụng xe tải. Mỗi gói hàng sẽ có một _yêu cầu thời gian_ - tức là, thời gian cần để vận chuyển gói hàng đó.
##### Bạn được cho một khoảng thời gian nhất định. Mục tiêu của bạn là vận chuyển càng nhiều gói hàng càng tốt trong khoảng _thời gian quy định_ đó.



##### Tóm lại, quy trình vận chuyển như sau:
- Một số gói hàng nhỏ sẽ được vận chuyển bằng xe thùng. Tổng _yêu cầu thời gian_ của chúng không được vượt quá _thời gian quy định_.
- Một số gói hàng nhỏ và lớn sẽ được vận chuyển bằng xe tải. Tổng _yêu cầu thời gian_ của chúng - dĩ nhiên - cũng không được vượt quá _thời gian quy định_.


## Đặc tả dữ liệu đầu vào
__Dữ liệu đầu vào được chứa trong file `DELIVERY.IN`.__
##### Cấu trúc file :
_Dòng đầu tiên_ :
chứa một số nguyên `T` với giới hạn `(1 ≤ T ≤ 1000)` - biểu thị _thời gian quy định_.

_Dòng thứ 2_ :
chứa một số nguyên `N` với giới hạn `(1 ≤ N ≤ 500)` biểu thị số lượng gói hàng cỡ nhỏ.

_Dòng thứ 3 đến `N + 2`_ :
mỗi dòng chứa một số nguyên có giới hạn `(1 ≤ X ≤ 1000)` - chỉ _yêu cầu thời gian_ của những gói hàng nhỏ, xếp theo thứ tự __tăng dần__.

_Dòng thứ `N + 3`_ : 
chứa một số nguyên `M` với giới hạn `(1 ≤ M ≤ 500)` biểu thị số lượng gói hàng cỡ lớn.

_Dòng thứ `N + 4` đến `N + M + 3`_ :
mỗi dòng chứa một số nguyên có giới hạn `(1 ≤ X ≤ 1000)` - chỉ _yêu cầu thời gian_ của những gói hàng lớn, xếp theo thứ tự __tăng dần__.


## Đặc tả dữ liệu đầu ra
__Dữ liệu đầu ra được ghi trong file `DELIVERY.IN`.__
Một dòng duy nhất, chứa số nguyên biểu thị số lượng gói hàng có thể được trung chuyển trong _thời gian quy định_.

## Các ví dụ
##### Ví dụ 1:
###### Dữ liệu đầu vào (file `DELIVERY.IN`):
```
10
8
2
2
2
2
2
4
4
4
4
3
3
6
6
```
###### Dữ liệu đầu ra (file `DELIVERY.OUT`):
```
8
```
###### Mô tả ví dụ:
_Thời gian quy định_ là 10 đơn vị thời gian.
Có 8 gói hàng nhỏ:
- 5 gói hàng có _yêu cầu thời gian_ là 2
- 3 gói hàng có _yêu cầu thời gian_ là 4
Có 4 gói hàng lớn:
- 2 gói hàng có _yêu cầu thời gian_ là 3
- 2 gói hàng có _yêu cầu thời gian_ là 6

8 gói hàng có thể được vận chuyển trong 10 đơn vị thời gian theo cách sắp xếp sau:
__Xe tải chở__ : 
- 1 gói hàng nhỏ : _yêu cầu thời gian_ là 4
- 2 gói hàng lớn : _yêu cầu thời gian_ là 3

__Xe thùng chở__ :
- 5 gói hàng nhỏ : _yêu cầu thời gian_ là 2
