class Resolution {
public:

	Resolution() {
		this->x = -1;
		this->y = -1;
	}

	Resolution(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}

private:

	int x;
	int y;

};