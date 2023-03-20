#pragma once

#include "cocos2d.h"
#include "stdafx.h"

struct PQNode
{
	// ���� �ű��
	//  F = G + H
	// F = ���� ���� (���� ���� ����. ��ο� ���� �޶���)
	// G = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ��� (���� ���� ����. ��ο� ���� �޶���)
	// H = �������κ��� �󸶳� ����� �������� ������ ���� (���� ���� ����. ����)
public:
	int F;
	int G;
	// F�� G�� �˾Ƶ� H�� ���� �� ������ ���� ( H = F - G)
	int Y;
	int X;
};



class Enemy : public cocos2d::Layer
{
public:
	Enemy();
	~Enemy();

	static Enemy* create(cocos2d::Node* _listener, Coordinate pos, cocos2d::SEL_CallFunc _selector);
	virtual bool init(cocos2d::Node* _listener, Coordinate pos, cocos2d::SEL_CallFunc _selector);

	cocos2d::Sprite* _enemy;
	Coordinate _pos;

	EnemyState _state = EnemyState::MOVE;

	cocos2d::Node* _listener;
	cocos2d::SEL_CallFunc _selector;

	/////////////////////////////////
	cocos2d::Vec2 direction;

private:
	// A* ���� ���� ���
	std::queue<PQNode> pq;

	int deltaY[4] = { -1, 0, 1, 0 };
	int deltaX[4] = { 0, -1, 0, 1 };
	int cost[4] = { 10, 10, 10, 10 };

	// ( y, x) �̹� �湮�ߴ��� ���� (�湮 = closed ����)
	bool closed[MAP_HEIGHT][MAP_WIDTH] = { 0, };

	// ���� ���
	int open[MAP_HEIGHT][MAP_WIDTH];

	// �Ÿ��� ���� node���� ���� �θ� ����
	Coordinate parent[MAP_HEIGHT][MAP_WIDTH];

	// ���� �̵��� ��� ����Ʈ
	std::list<Coordinate> _points;

	// ���� ��ǥ ������Ʈ �ϱ����� Ȯ�� ��ǥ
	Coordinate confirmPos = Coordinate(0, 0);
	// �̵��� ���� ��ǥ ��ǥ
	Coordinate dest = Coordinate(0, 0);

	bool isDefaultMove = false;
	bool isSearchMove = false;

	float _speed = 50.0f;

	void update(float f);
	void SetDestPos();
	// Astar �����͵� �ʱ�ȭ
	void InitAstar();
	// Astar ������ ����
	void Astar();
	// Astar ������ ������� ���� ��� ����
	void CalcPathFromParent(Coordinate dest);
};

