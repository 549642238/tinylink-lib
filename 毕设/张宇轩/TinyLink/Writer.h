#ifndef WRITER_H
#define WRITER_H

template <typename T>
class Writer  {
public:
	virtual void write(T data)=0;
};

#endif
