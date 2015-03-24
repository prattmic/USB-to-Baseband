#ifndef __SYMBOL_H
#define __SYMBOL_H

#include "iq.h"
#include "types.h"
#include "container.h"

#define SQRT2_INV 0.70710678118f

/* This will blow up if the struct symbol_stream in your struct is not named stream */
#define to_bpsk_stream(__ss) container_of(__ss, struct bpsk_stream, stream)
#define to_qpsk_stream(__ss) container_of(__ss, struct qpsk_stream, stream)
#define to_sample_hold(__ss) container_of(__ss, struct sample_hold, stream)

/*
 * Easy macro for iterating through all symbols in stream.
 * arguments: pointer to store current symbol, stream to go through
 */
#define for_each_symbol(__sym, __ss) \
		 while ((__ss)->get_symbol((__ss), (__sym)))

/*
 * A symbol stream is a handle that contains the function
 * for the specific implementation of symbol_stream
 */
struct symbol_stream {
	int (*get_symbol)(struct symbol_stream *, struct iq *);
	int (*len)(struct symbol_stream *);
};

struct bpsk_stream {
	int len;
	int bits;
	int bit_idx;
	struct symbol_stream stream;
	u8 *data;
};

struct qpsk_stream {
	int len;
	int bits;
	int bit_idx;
	struct symbol_stream stream;
	u8 *data;
};

struct sample_hold {
	int count;
	int hold;
	struct iq current;
	struct symbol_stream *orig_stream;
	struct symbol_stream stream;
};

int init_bpsk_stream(struct bpsk_stream *bs, u8 *data, int n);
int init_qpsk_stream(struct qpsk_stream *qs, u8 *data, int n);
#endif /* __SYMBOL_H */
