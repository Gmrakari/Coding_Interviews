

/*
 * Date:2021-09-29 21:09
 * filename:05_单例模式.cpp
 *
 */


class Single {
public:
	Single() {
		return p;
	}
private:
	static Single *p;
};
