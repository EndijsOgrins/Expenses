#pragma once

#include <vector>
#include <ostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <iomanip>

class ExpenseSheet {
	public:
		struct Entry {
			std::string lable;
			double value = 0;

			inline bool operator==(const Entry& rhs) const {
				return lable == rhs.lable;
			}

		};

	public:
		ExpenseSheet() = default;
		ExpenseSheet(const ExpenseSheet&) = default;

		ExpenseSheet& operator=(const ExpenseSheet&) = default;

		bool Add(std::string_view label, double value);
		bool Del(std::string_view label);
		void List(std::ostream& os) const;
		double Eval() const;

	private:
		std::vector<Entry> m_entrys;
};