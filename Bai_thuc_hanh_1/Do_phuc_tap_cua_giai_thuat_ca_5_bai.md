# Đánh giá độ phức tạp thuật toán

Ký hiệu: **n** là giá trị đầu vào (hoặc số phần tử của mảng).

| Bài | Thuật toán | Thời gian | Không gian |
|-----|-----------|-----------|------------|
| 1 | Giải phương trình bậc 2 | O(1) | O(1) |
| 2 | Kiểm tra số nguyên tố | O(√n) | O(1) |
| 3 | Nhập mảng và tìm giá trị lớn nhất | O(n) | O(n) |
| 4 | Tìm BCNN bằng thuật toán Euclid | O(log(min(a, b))) | O(1) |
| 5 | Kiểm tra số hoàn hảo | O(n) | O(1) |

## Giải thích

- **Bài 1:** chỉ gồm các phép so sánh và tính toán cố định, không có vòng lặp nên O(1).
- **Bài 2:** vòng lặp `i` chạy từ 2 đến √n nên O(√n).
- **Bài 3:** hai vòng lặp tuần tự (nhập và tìm max), mỗi vòng n lần nên O(n) + O(n) = O(n). Không gian O(n) để lưu mảng.
- **Bài 4:** mỗi hai bước lặp của Euclid thì số dư giảm ít nhất một nửa nên O(log(min(a, b))).
- **Bài 5:** vòng lặp `i` chạy từ 1 đến n/2 nên O(n).
