#ifndef RESULT_H_
#define RESULT_H_

typedef enum {
	Success,
	InvalidSize,
	InvalidIndex,
	InvalidReference,
	OutOfMemory,
	NotFound,
	ArgumentNull,
	InvalidArgument
} Result;

#endif // RESULT_H_
