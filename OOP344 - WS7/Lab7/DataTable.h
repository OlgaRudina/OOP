#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
namespace w7 {

	template <typename T>
	class DataTable {

	private:

		vector<T> _xs;
		vector<T> _ys;
		int _FW;
		int _ND;

	public:
		DataTable(ifstream& in, int FW, int ND) : _FW(FW), _ND(ND) {

			T x, y;
			while (!in.eof()) {
				in >> x >> y;
				_xs.push_back(x);
				_ys.push_back(y);
			}
		}

		T mean() const {
			T sum = accumulate(_ys.begin(), _ys.end(), (T)0);
			T num = _ys.size();

			return sum / num;
		}

		T sigma() const {
			T mean_ = mean();
			T num = _ys.size();

			vector<T> diff(num);
			transform(_ys.begin(), _ys.end(), diff.begin(), bind2nd(minus<T>(), mean_));

			T sum_sq = inner_product(diff.begin(), diff.end(), diff.begin(), (T)0);
			return (T)sqrt(sum_sq / (num - 1));
		}

		T median() const {
			vector<T> sort_ = this->_ys;
			sort(sort_.begin(), sort_.end());
			T num = _ys.size();

			return sort_[num / 2];
		}

		void regression(T& slope, T& y_intercept) const {

			T sum_xy = inner_product(_xs.begin(), _xs.end(), _ys.begin(), (T)0);
			T sum_x = accumulate(_xs.begin(), _xs.end(), (T)0);
			T sum_y = accumulate(_ys.begin(), _ys.end(), (T)0);
			T sum_sq_x = inner_product(_xs.begin(), _xs.end(), _xs.begin(), (T)0);
			T num = _ys.size();
			slope = (num * sum_xy - sum_x * sum_y) / (num * sum_sq_x - sum_x * sum_x);
			y_intercept = (sum_y - slope * sum_x) / num;
		}

		void display(ostream& os) const {
			os << setprecision(_ND) << fixed;
			os << setw(_FW) << 'x' << setw(_FW) << 'y' << endl;

			for (int i = 0; i < _xs.size(); i++) {
				os << setw(_FW) << _xs[i] << setw(_FW) << _ys[i] << endl;
			}
		}

		friend ostream& operator<<(ostream& os, const DataTable& D) {
			D.display(os);
			return os;
		}
	};
}