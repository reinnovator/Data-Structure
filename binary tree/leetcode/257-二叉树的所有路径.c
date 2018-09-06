/*************************************************************************
	> File Name: 257-二叉树的所有路径.c
	> Author: 
	> Mail: 
	> Created Time: 四  9/ 6 16:48:04 2018
 ************************************************************************/

char** result;
int head;

int getResult(struct TreeNode* root,int path[],int index){
    if(root==NULL)return 0;
    path[index]=root->val;
    if(root->left==NULL&&root->right==NULL){
        if(index>=0){
            char* tmp=(char*)malloc(sizeof(char)*1000);
            int count=0;
            for(int i=0;i<=index;i++){
                char* num=(char*)malloc(sizeof(char)*10);
                sprintf(num,"%d",path[i]);
                strcat(tmp,num);
                count+=strlen(num);
                if(i<index){
                    tmp[count++]='-';
                    tmp[count++]='>';
                }
            }
            result[head++]=tmp;
            result=(char**)realloc(result,sizeof(char*)*(head+1));
        }
    }
    if(root->left)getResult(root->left, path, index+1);
    if(root->right)getResult(root->right, path, index+1);
    return 0;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    result=(char**)malloc(sizeof(char*));
    head=0;
    int path[10000];
    getResult(root,path,0);
    *returnSize=head;
    return result;
}
