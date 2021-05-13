#include <cstdlib>
#include "stdio.h"
#include <string>
#include "leptjson.h"

static int main_ret=0;
static int test_count=0;
static int test_pass=0;

#define EXPECT_EQ_BASE(equality,expect,actual,format) \
	do{\
		test_count++;\
		if(equality)\
			test_pass++;\
		else{\
			printf(stderr,"%s:%d: expect: "format" actual: "format"\n",__FILE__,__LINE__,expect,actual);\
		main_ret=1;
		}\
	}while(0)

#define EXPECT_EQ_INT(expect,actual) EXPECT_EQ_BASE(expect==actual,expect,actual,"%d")

static void test_parse_null(){
	lept_value v;
	v.type=LEPT_FALSE;
	EXPECT_EQ_INT(LEPT_PARSE_OK,lept_parse(&v,"null"));
	EXPECT_EQ_INT(LEPT_NULL,lept_get_type(&v));
}

static void test_parse_invalid_value(){
	lept_value v;
	v.type= LEPT_FALSE;
		
