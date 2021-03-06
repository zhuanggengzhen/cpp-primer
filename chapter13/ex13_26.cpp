#include "ex13_26.h"
ConstStrBlobPtr StrBlob::begin() const {return ConstStrBlobPtr(*this);}
ConstStrBlobPtr StrBlob::end() const {return ConstStrBlobPtr(*this, data->size());}
StrBlob &StrBlob::operator=(const StrBlob &sb)
{
	data = std::make_shared<std::vector<std::string>>(*sb.data);
	return *this;
}

int main()
{
	return 0;
}
