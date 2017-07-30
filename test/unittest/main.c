#include"main.h" 
#include"stdlib.h"
#include"stdint.h"
#include"stdbool.h"
#include"testl.h"
bool __TestExS_test();
char* __TestSingleton_getName(TestSingleton* this);
bool __TestSingleton_test(TestSingleton* this);
TestSingleton testSingleton={.name="tom",.getName=&__TestSingleton_getName,.test=&__TestSingleton_test};
bool __TestList_append(TestList** this,void* data);
int32_t __TestList_print(TestList** this);
bool __TestStruct_testS(TestStruct* this);
bool testLocal();
int main()
{
printf("starting test!\n");
checkTest("loop",testloop());
TestStruct tStruct = __crt_TestStruct();
TestStruct* tStructp = __new_TestStruct();
checkTest("struct",tStruct.testS(&tStruct)&&tStructp->testS(tStructp));
free(tStructp);
checkTest("condition",testCondition());
checkTest("args",testArgs(15,true,"test"));
checkTest("local",testLocal());
TestList* mlist = __new_TestList();
mlist->data="my";
mlist->append(&mlist,"test");
mlist->append(&mlist,"list");
mlist->append(&mlist,"working");
checkTest("list",mlist->print(&mlist)==4);
free(mlist);
checkTest("lib",testLib());
checkTest("pointer",testPointer());
checkTest("singleton",testSingleton.test(&testSingleton));
checkTest("functionPointer",testFuncPointer(&testFuncPointerFunc,(30!=3)));
struct TestStructTag testStructTag = __crt_TestStructTag();
checkTest("struct tag",testStructTag.res);
checkTest("double arr",testExpressions());
TestIDType testidtype;
testidtype=__crt_TestIDType();
checkTest("id as type",testidtype.res);
checkTest("array access",testArray());
return 0;}
bool testArray()
{
int* tempS = malloc(sizeof(int)*10);
TestArrayS testnum = __crt_TestArrayS();
tempS[testnum.num]=5;
bool res = true;
for(int i = 0;i<10;i++){
tempS[i]=i;
}
for(int i = 0;i<10;i++){
if(tempS[i]!=i)res=false;
}
return res;}
TestArrayS* __new_TestArrayS()
{ 
TestArrayS *this = malloc(sizeof(TestArrayS));
this->num = 6; 
return this;
} 
TestArrayS __crt_TestArrayS()
{ 
TestArrayS this;
this.num = 6; 
return this;
} 
TestIDType* __new_TestIDType()
{ 
TestIDType *this = malloc(sizeof(TestIDType));
this->res = true; 
return this;
} 
TestIDType __crt_TestIDType()
{ 
TestIDType this;
this.res = true; 
return this;
} 
bool testExpressions()
{
TestExS* testExS = __new_TestExS();
testExS->start=__new_TestExS();
int32_t num = 0;
num+=10;
testExS->start->num+=10;
if(testExS->start->start){
return false;
}
bool res = testExS->start->test();
free(testExS->start);
free(testExS);
return res;}
bool __TestExS_test()
{
return true;}
TestExS* __new_TestExS()
{ 
TestExS *this = malloc(sizeof(TestExS));
this->start = NULL; 
this->num = 0; 
this->test = &__TestExS_test; 
return this;
} 
TestExS __crt_TestExS()
{ 
TestExS this;
this.start = NULL; 
this.num = 0; 
this.test = &__TestExS_test; 
return this;
} 
TestStructTag* __new_TestStructTag()
{ 
TestStructTag *this = malloc(sizeof(TestStructTag));
this->res = true; 
return this;
} 
TestStructTag __crt_TestStructTag()
{ 
TestStructTag this;
this.res = true; 
return this;
} 
void checkTest(char* name,bool res)
{
if(res){
printf("test: %s succeeded! \n",name);
}else{
printf("test: %s failed! \n",name);
}}
bool testFuncPointer(__testFuncPointer_testFuncP testFuncP,bool res)
{
return (testFuncP(&testFuncPointerRes)&&res);}
bool testFuncPointerFunc(__testFuncPointerFunc_res res)
{
return (res(10==10)&&true);}
bool testFuncPointerRes(bool res2)
{
return res2;}
char* __TestSingleton_getName(TestSingleton* this)
{
return this->name;}
bool __TestSingleton_test(TestSingleton* this)
{
if(strcmp(this->getName(this),"tom")==0)return true;
return false;}
TestSingleton* __new_TestSingleton()
{ 
TestSingleton *this = malloc(sizeof(TestSingleton));
this->name = "tom"; 
this->getName = &__TestSingleton_getName; 
this->test = &__TestSingleton_test; 
return this;
} 
TestSingleton __crt_TestSingleton()
{ 
TestSingleton this;
this.name = "tom"; 
this.getName = &__TestSingleton_getName; 
this.test = &__TestSingleton_test; 
return this;
} 
bool __TestList_append(TestList** this,void* data)
{
while(*this){
this=&((*this)->next);
}
*this=__new_TestList();
(*this)->data=data;
return true;}
int32_t __TestList_print(TestList** this)
{
int32_t count = 0;
while(*this){
printf("element: %i = %s\n",count,(char*)(*this)->data);
this=&((*this)->next);
count++;
}
return count;}
TestList* __new_TestList()
{ 
TestList *this = malloc(sizeof(TestList));
this->data = NULL; 
this->next = NULL; 
this->prev = NULL; 
this->append = &__TestList_append; 
this->print = &__TestList_print; 
return this;
} 
TestList __crt_TestList()
{ 
TestList this;
this.data = NULL; 
this.next = NULL; 
this.prev = NULL; 
this.append = &__TestList_append; 
this.print = &__TestList_print; 
return this;
} 
bool testPointer()
{
char* testp = "hello";
char** testp1 = &testp;
char** res = malloc(sizeof(char*));
*res=malloc(sizeof(char)*6);
strcpy(*res,"hello");
if(strcmp(*res,*testp1)==0){
free(*res);
free(res);
return true;
}else{
free(*res);
free(res);
return false;
}}
bool __TestStruct_testS(TestStruct* this)
{
return this->res;}
TestStruct* __new_TestStruct()
{ 
TestStruct *this = malloc(sizeof(TestStruct));
this->res = true; 
this->testS = &__TestStruct_testS; 
return this;
} 
TestStruct __crt_TestStruct()
{ 
TestStruct this;
this.res = true; 
this.testS = &__TestStruct_testS; 
return this;
} 
bool testLocal()
{
return true;}
bool testArgs(int32_t num,bool res,char* txt)
{
if(num!=15)res=false;
if(strcmp("test",txt)!=0)res=false;
return res;}
bool testCondition()
{
bool res = true;
if(true||false){
res=true;
}else if(true){
res=false;
}else{
res=false;
}
int32_t tnum = NULL;
while(!tnum){
tnum=10;
}
if(tnum!=10)res=false;
return res;}
bool testloop()
{
bool res = true;
int32_t count = 0;
for(int32_t i = 0;i<15;i++){
count++;
}
if(count!=15)res=false;
for(int32_t i = 15;i>0;i--){
count--;
}
if(count!=0)res=false;
while(count<(15-5)){
count++;
}
if(count!=10)res=false;
return res;}
