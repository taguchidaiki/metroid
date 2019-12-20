#pragma once
#ifdef _DEBUG
#include "cocos2d.h"
#include <memory>
#include <chrono>		//精度は1ms程度

//Draw関数群
#define _dbgDrawString(fmt, ...) _DebugGraph::GetInstance().DrawString(fmt, __VA_ARGS__);
#define _dbgDrawFormatString(fmt,...) _DebugGraph::GetInstance().SetScreen();\
										DxLib::DrawFormatString(fmt,__VA_ARGS__);\
										_DebugGraph::GetInstance().RevScreen();

#define _dbgDrawPixel(fmt, ...) _DebugGraph::GetInstance().DrawPixel(fmt, __VA_ARGS__);
#define _dbgDrawLine(fmt, ...) _DebugGraph::GetInstance().DrawLine(fmt, __VA_ARGS__);
#define _dbgDrawBoxCC(fmt, ...) _DebugGraph::GetInstance().DrawBoxCC(fmt, __VA_ARGS__);
#define _dbgDrawCircle(fmt, ...) _DebugGraph::GetInstance().DrawCircle(fmt, __VA_ARGS__);


//_DebugGraph設定関数群
#define _dbgStartGraph		_DebugGraph::GetInstance().StartDbgGraph();
#define _dbgAddScreen		_DebugGraph::GetInstance().AddDbgScreen();
#define _dbgSetUpGraph(A)	_DebugGraph::GetInstance().SetUpGraph(A);
#define _dbgSetAlpha(A)		_DebugGraph::GetInstance().SetAlpha(A);

using ChronoSysClock = std::chrono::system_clock::time_point;

class _DebugGraph
{
public:
	static _DebugGraph& GetInstance(void)
	{
		return (*s_Instance);
	}

	int DrawString(int x, int y, const char *String, unsigned int Color, bool InFlag = true);

	int DrawPixel(int x, int y, unsigned int Color);
	int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color);
	bool DrawBoxCC(cocos2d::Scene& scene, const cocos2d::Layer&  layer);
	bool DrawBoxCC(cocos2d::Scene& scene, const cocos2d::Node& sp);
	bool DrawBoxCC(cocos2d::Sprite& sp, cocos2d::Color4F color);
	int DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag);
	
	bool StartDbgGraph(void);
	bool AddDbgScreen(void);
	bool SetUpGraph(int alpha);
	bool SetAlpha(int alpha);

	bool SetScreen(void);
	bool RevScreen(void);


private:
	struct _DebugGraphDeleter
	{
		void operator()(_DebugGraph* _debugGraph)const
		{
			delete _debugGraph;
		}
	};

	_DebugGraph();
	~_DebugGraph();


	int _alpha;
	int _dbScreen;
	int _ghBuffer;
	bool _rtnFlag;
	
	double _waitTime;
	ChronoSysClock _start;
	ChronoSysClock _end;

	static std::unique_ptr<_DebugGraph,_DebugGraph::_DebugGraphDeleter> s_Instance;
};
#else
#define _dbgDrawString(fmt,...)
#define _dgbDrawFormatString(fmt,...)
#define _dbgDrawPixel(fmt, ...)
#define _dbgDrawLine(fmt, ...)
#define _dbgDrawBoxCC(fmt, ...)
#define _dbgDrawCircle(fmt, ...)

#define _dbgStartGraph
#define _dbgAddScreen
#define _dbgSetUpGraph(A)
#define _dbgSetAlpha(A)
#endif

