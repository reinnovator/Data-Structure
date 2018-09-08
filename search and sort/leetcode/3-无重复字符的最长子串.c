/*************************************************************************
	> File Name: 3-无重复字符的最长子串.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 17:49:14 2018
 ************************************************************************/
#if 1
int lengthOfLongestSubstring(char* s) {
#define CHAR_MAX 256
    int hashTab[CHAR_MAX] = {0}; //0-- index  1--len
    int i = 0, j = 0, strLen = 0, maxLen = 0, tmpMaxLen = 0;
    int newSubStr = 0; //假设如果只有一个字符 那么上次找到的地方就是前面
    if (NULL == s)
    {
        return 0;
    }
    strLen = strlen(s);
    for (i = 0; i < CHAR_MAX; i++)
    {
        hashTab[i] = -1;
    }
    
    for (i = 0; i < strLen; i++)
    {
        if ((hashTab[*(s+i)] < newSubStr))
        {
            hashTab[*(s+i)] = i;
            tmpMaxLen++;
        } else { //meet a same
            /*计算原来的*/
            maxLen = tmpMaxLen > maxLen ? tmpMaxLen : maxLen;
            
            //代表新的一轮计数开始
            newSubStr = hashTab[*(s+i)] + 1;
            tmpMaxLen = i - newSubStr + 1;//代表新的一轮计数开始 +1是因为new和i都是新的长度
            hashTab[*(s+i)] = i;
        }
    }
    maxLen = tmpMaxLen > maxLen ? tmpMaxLen : maxLen;
    
    return maxLen;
}
#endif
