template <class T>
class IUVector
{
public:
	IUVector()
		: size_(0) {}

	explicit IUVector(size_t size)
	{
		size_ = size;
		vector_ = new T[size_];
		memset(vector_, 0, size_ * vector_[0]);
	}

	IUVector(const IUVector <T>&copy)
		:size_(copy.size_)
	{
		vector_ = new T[size_];
		for (size_t i = 0; i < size_; i++)
			vector_[i] = copy.vector_[i];
	}

	IUVector(size_t size, const T massive)
		:size_(size)
	{
		vector_ = new T[size_];
		for (size_t i = 0; i < size_; i++)
			vector_[i] = massive[i];
	}

	size_t size() const
	{
		return size_;
	}

	IUVector reSize(size_t size)
	{
		delete[] vector_;
		size_ = size;
		vector_ = new T[size_];
		memset(vector_, 0, size_ * vector_[0]);
		return *this;
	}

	operator double *()
	{
		return this->vector_;
	}

	IUVector &operator = (const IUVector <T>&vector)
	{
		if (&vector == this)
			return *this;
		delete[] vector_;
		size_ = vector.size_;
		vector_ = new T[size_];
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector.vector_[i];
		return *this;
	}

	T *operator * (T number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] * number;
		return vector_;
	}

	T *operator *= (T number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] * number;
		return vector_;
	}

	T *operator / (T number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] / number;
		return vector_;
	}

	T *operator /= (T number)
	{
		for (size_t i = 0; i < size_; i++)
			vector_[i] = vector_[i] / number;
		return vector_;
	}

	~IUVector()
	{
		delete[] vector_;
	}

	T &operator [] (size_t);

	template<class T> friend std::ostream &operator << (std::ostream &, IUVector <T>&);

private:
	T *vector_;
	size_t size_;
};

template<class T>
T &IUVector<T>::operator [] (size_t index)
{
	return vector_[index];
}

template <class T>
std::ostream &operator << (std::ostream &out, IUVector <T>&vector)
{
	out << "Vector: (";
	for (size_t i = 0; i < vector.size_; i++)
	{
		out << vector.vector_[i];
		if (i == vector.size_ - 1)
			out << ")" << std::endl;
		else
			out << ", ";
	}
	return out;
}
