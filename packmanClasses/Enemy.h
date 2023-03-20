#pragma once

#include "cocos2d.h"
#include "stdafx.h"

struct PQNode
{
	// 점수 매기기
	//  F = G + H
	// F = 최종 점수 (작을 수록 좋음. 경로에 따라 달라짐)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용 (작을 수록 좋음. 경로에 따라 달라짐)
	// H = 목적지로부터 얼마나 가까운 곳인지를 따지는 점수 (작을 수록 좋음. 고정)
public:
	int F;
	int G;
	// F랑 G만 알아도 H는 구할 수 있으니 생략 ( H = F - G)
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
	// A* 계산용 개별 노드
	std::queue<PQNode> pq;

	int deltaY[4] = { -1, 0, 1, 0 };
	int deltaX[4] = { 0, -1, 0, 1 };
	int cost[4] = { 10, 10, 10, 10 };

	// ( y, x) 이미 방문했는지 여부 (방문 = closed 상태)
	bool closed[MAP_HEIGHT][MAP_WIDTH] = { 0, };

	// 열린 목록
	int open[MAP_HEIGHT][MAP_WIDTH];

	// 거리가 계산된 node들의 개별 부모 정보
	Coordinate parent[MAP_HEIGHT][MAP_WIDTH];

	// 최종 이동할 경로 리스트
	std::list<Coordinate> _points;

	// 최종 목표 업데이트 하기전의 확인 좌표
	Coordinate confirmPos = Coordinate(0, 0);
	// 이동할 최종 목표 좌표
	Coordinate dest = Coordinate(0, 0);

	bool isDefaultMove = false;
	bool isSearchMove = false;

	float _speed = 50.0f;

	void update(float f);
	void SetDestPos();
	// Astar 데이터들 초기화
	void InitAstar();
	// Astar 데이터 세팅
	void Astar();
	// Astar 데이터 기반으로 최종 경로 세팅
	void CalcPathFromParent(Coordinate dest);
};

