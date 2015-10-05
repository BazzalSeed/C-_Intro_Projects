class fml{
public:
	int seed;
	int seed_sucks;

	fml();
	fml(const fml & fanother);

	int  x() const;
	int y() const;
	void x(int c);
	void y(int c);

};