enum num_precision {
	/* Note, signed are always even */
	I_LIT=0,
	I_LIT_U,
	L_LIT,
	L_LIT_U,
	LL_LIT,
	LL_LIT_U,
	F_LIT,
	D_LIT,
	LD_LIT,
};


struct string_lit {
	char *string_lit;
	int string_size;
};

struct num_lit {
	char sign_and_precision;
	union {
		int i_lit;
		unsigned int i_lit_u;
		long l_lit;
		unsigned long l_lit_u;
		long long ll_lit;
		unsigned long long ll_lit_u;
		float f_lit;
		double d_lit;
		long double ld_lit;
	};
};
