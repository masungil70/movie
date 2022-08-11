#pragma once

class Money {
public:
	static Money wons(int amount) {
		return Money(amount);
	}

	Money(int amount) : amount_(amount) {

	}

	Money plus(const Money& money) const {
		return Money(this->amount_ + money.amount_);
	}

	Money minus(const Money& money) const {
		return Money(this->amount_ - money.amount_);
	}

	Money times(double percent) const {
		return Money((int)(this->amount_ * percent));
	}

	bool operator < (const Money& other) const {
		return (this->amount_ < other.amount_);
	}

	bool operator >= (const Money& other) const {
		return (this->amount_ >= other.amount_);
	}

	static const Money ZERO;

	int getAmount() const {
		return amount_;
	}
private:
	int	amount_;

};