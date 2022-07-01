#pragma once
#ifndef btree_H_
#define btree_H_
#include"Setting.h"
#include<vector>
#include<string>

using namespace std;

class node
{
public:
	node* left;
	node* right;
	Setting* data;
	node()
	{
		left = NULL;
		right = NULL;
	}
};

class btree
{
private:
	int num;//kích thước danh sách
	int a = 1;//đếm số xe thứ
	int theodoi = 0;//biến theo dõi xe đã tồn tại hay chưa
	int ghifile = 0; //biến kiểm tra file đã được ghi và cập nhật

public:
	btree();
	~btree();
	int getSize();//size của cây

	void insertNodeKey(node* & pNode, Setting* key); //thêm node đại diện là key vào cây
	void insertNodeName(node*& pNode, Setting* name);//thêm node đại diện là name vào cây

	void thaytheData(node*& pNode, Setting* name,int thongbao);

	void inforDisplay(node*& pNode);//thông tin Display
	void inforSound(node*& pNode);//thông tin Sound
	void inforGeneral(node*& pNode);//Thông tin General
	void inforAll(node*& pNode);//Thông tin all

	void writeFile(node*& pNode); //ghi dữ liệu vào file Setting.txt

	bool findNode(node*& pNode, Setting* key);//đưa ra thông báo xe đã tồn tại hay chưa
	void replaceNodeKey(node*& pNode, Setting* key, int thongbao); //thay thế node khi xe đã trùng key
	void replaceNodeName(node*& pNode, Setting* key, int thongbao); //thay thế node khi xe đã trùng key

	void sortNode(node*& pNode,int index);//sắp xếp xe theo tên hoặc MSCN
	void deletebtree(node*& pNode);
};
#endif /* btree_H_ */
