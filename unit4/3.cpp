#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum {
	NPREF  = 2,
	NHASH  = 5,
	MAXGEN = 10000
};
typedef struct State State;
typedef struct Suffix Suffix;
struct State {
	char *pref[NPREF];
	Suffix *suf;
	State *next;
};
struct Suffix {
	char *word;
	Suffix *next;
};
State *statetab[NHASH];

enum {MULTIPLIER = 31};
unsigned int hash(char *s[NPREF]) {
	unsigned int h = 0;
	unsigned char *p;
	for(int i = 0; i < NPREF; i++)
		for(p = (unsigned char *)s[i]; *p != '\0'; p++)
			h = MULTIPLIER*h + *p;
	return h % NHASH;
}

State *lookup(char *prefix[NPREF], int create) {
	int i;
	State *sp;
	int h = hash(prefix);
	for(sp = statetab[h]; sp != NULL; sp = sp->next) {
		for(i = 0; i < NPREF; i++)
			if (strcmp(prefix[i], sp->pref[i]) != 0)
				break;
		if (i == NPREF)
			return sp;
	}
	if (create) {
		sp = (State *)malloc(sizeof(State));
		if (sp == NULL) {
			perror("Memory allocation error.");
			exit(EXIT_FAILURE);
		}
		for(i = 0; i < NPREF; i++)
			sp->pref[i] = prefix[i];
		sp->suf = NULL;
		sp->next = statetab[h];
		statetab[h] = sp;
	}
	return sp;
}

char *mystrdup(char *s) {
	char *t;
	t = (char *) malloc(strlen(s)+1);
	if (t == NULL) {
		perror("Error: strdup failed.");
		exit(EXIT_FAILURE);
	}
	strcpy(t, s);
	return t;
}

void addsuffix(State *sp, char *suffix) {
	Suffix *suf;
	suf = (Suffix *) malloc(sizeof(Suffix));
	if (suf == NULL) {
		perror("Memory allocation error.");
		exit(EXIT_FAILURE);
	}
	suf->word = suffix;
	suf->next = sp->suf;
	sp->suf = suf;
}

void add(char *prefix[NPREF], char *suffix) {
	State *sp;
	sp = lookup(prefix, 1);
	addsuffix(sp, suffix);
	memmove(prefix, prefix+1, (NPREF-1)*sizeof(prefix[0]));
	prefix[NPREF-1] = suffix;
}

void build(char *i_prefix[NPREF], char *f_prefix[NPREF], FILE *f) {
	char buf[100], fmt[10];
	char *word;
	int count = 0;
	sprintf(fmt, "%%%lds", sizeof(buf)-1);
	printf("fmt = \"%s\"\n", fmt);
	while (fscanf(f, fmt, buf) != EOF) {
		word = mystrdup(buf);
		printf("%s ", buf);
		if (count < NPREF) {
			i_prefix[count] = word; //first 2 words
			f_prefix[count] = word; //-//-
			count++;
		} else {
			add(f_prefix, word); //finding last 2 words
		}
	}
	printf("*%s*", f_prefix[0]);
	putchar('\n');
}

void generate(char *i_prefix[NPREF], char *f_prefix[NPREF], int nwords) {
	
	//printf("*%s*", f_prefix[0]);
	State *sp;
	Suffix *suf;
	char *prefix[NPREF], *w;
	int i, j, nmatch;
	for(i = 0; i < NPREF; i++) {
		prefix[i] = i_prefix[i]; // First two words.
	}
	for(i = 0; i < nwords; i++) {
		sp = lookup(prefix, 0);
		if (sp == NULL)
			break;
		nmatch = 0;
		for(suf = sp->suf; suf != NULL; suf = suf->next)
			if (rand() % ++nmatch == 0)
				w = suf->word;
		if (nmatch == 0) {
			printf("internal error: no suffix %d %s", i, prefix[0]);
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < NPREF; j++)
			if (strcmp(prefix[j], f_prefix[j]) != 0) // comparing 
												//string with last 2 words
				break;
		if (j == NPREF && rand() % (nmatch + 1) == 0)
			break; //if prefix words is the last
		printf("%s\n", w);
		memmove(prefix, prefix+1, (NPREF-1)*sizeof(prefix[0]));
		prefix[NPREF-1] = w;
	}
}

int main() {
	int i, nwords = MAXGEN;
	char *i_prefix[NPREF]; //Àrray for first 2 words
	char *f_prefix[NPREF];
	for(i = 0; i < NPREF; i++) 
		i_prefix[i] = NULL;

	FILE *file;
	file = fopen("brooks.txt", "r");
	if (file) {
		build(i_prefix, f_prefix, file);
		fclose(file);
	}
	for (i = 0; i < NPREF && i_prefix[i] != NULL; i++) //Printing first 2 words
		printf("%s\n", i_prefix[i]);
	if (i == NPREF) // If original file consist more than 2 words
		generate(i_prefix, f_prefix, nwords - NPREF); 
		//first 2 words, '\n', quantity of words
	return 0;
}
