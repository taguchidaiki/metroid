#ifdef _DEBUG
#include "_DebugGraph.h"

std::unique_ptr<_DebugGraph, _DebugGraph::_DebugGraphDeleter>_DebugGraph::s_Instance(new _DebugGraph);


int _DebugGraph::DrawString(int x, int y, const char * String, unsigned int Color, bool InFlag)
{
	/*int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);*/
	int rtnFlg;
	/*if (InFlag)
	{
		rtnFlg = DxLib::DrawString(x + lpSceneMng.gameScreenPos.x, y + lpSceneMng.gameScreenPos.y, String, Color);
	}
	else
	{
		rtnFlg = DxLib::DrawString(x, y, String, Color);
	}
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);*/
	return rtnFlg;
}

int _DebugGraph::DrawPixel(int x, int y, unsigned int Color)
{
	/*int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);*/
	int rtnFlg;
	/*rtnFlag = DxLib::DrawPixel(x + lpSceneMng.gameScreenPos.x, y + lpSceneMng.gameScreenPos.y, Color);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);*/
	return rtnFlg;
}

int _DebugGraph::DrawLine(int x1, int y1, int x2, int y2, unsigned int Color)
{
	/*int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);*/
	int rtnFlg;
	/*rtnFlg = DxLib::DrawLine(x1 + lpSceneMng.gameScreenPos.x, y1 + lpSceneMng.gameScreenPos.y,
								  x2 + lpSceneMng.gameScreenPos.x, y2 + lpSceneMng.gameScreenPos.y,
								 Color);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);*/
	return rtnFlg;
}

bool _DebugGraph::DrawBoxCC(cocos2d::Scene& scene, const cocos2d::Layer&  layer)
{
	for (auto& sp : layer.getChildren())
	{
		DrawBoxCC(scene,(*sp));
	}
	
	//scene.getChildByName("");
	//scene.addChild();
	return true;
}

bool _DebugGraph::DrawBoxCC(cocos2d::Scene& scene, const cocos2d::Node & sp)
{
	auto square = cocos2d::DrawNode::create();
	//square->setAnchorPoint(cocos2d::Vec2(0, 0));
	square->drawRect(sp.getPosition(), sp.getPosition() + sp.getContentSize(), cocos2d::Color4F::WHITE);
	//square->setPosition(sp.getPosition());
	scene.addChild(square);
	
	/*for (const auto& child : sp.getChildren())
	{
		auto square = cocos2d::DrawNode::create();
		square->drawRect(child->getPosition(), child->getPosition() + child->getContentSize(), cocos2d::Color4F::WHITE);
		square->setPosition(child->getPosition());
		scene.addChild(square);
	}*/

	return true;
}

//当たり判定を目視したいオブジェクト自身、Color4FのコンテンツもしくはColor4f(r,g,b,α)
bool _DebugGraph::DrawBoxCC(cocos2d::Sprite & sp, cocos2d::Color4F color)
{
	auto square = cocos2d::DrawNode::create();
	square->drawRect(cocos2d::Vec2((sp.getTextureRect().origin / 2) - (sp.getTextureRect().size / 2)),
					 cocos2d::Vec2((sp.getTextureRect().origin / 2) + (sp.getTextureRect().size / 2)),
					 color);
	sp.addChild(square);
	return true;
}

int _DebugGraph::DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag)
{
	/*int ghBuffer;
	ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);*/
	int rtnFlg;
	//rtnFlg = DxLib::DrawCircle(x + lpSceneMng.gameScreenPos.x, y + lpSceneMng.gameScreenPos.y, r, Color, FillFlag);
	/*SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(ghBuffer);*/
	return rtnFlg;
}

bool _DebugGraph::StartDbgGraph(void)
{
	//int ghBuffer;
	//ghBuffer = GetDrawScreen();

	//SetDrawScreen(_dbScreen);
	////ClsDrawScreen();
	//SetDrawScreen(ghBuffer);

	return true;
}

bool _DebugGraph::AddDbgScreen(void)
{
	/*if (CheckHitKey(KEY_INPUT_PGUP))
	{
		_rtnFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_PGDN))
	{
		_rtnFlag = false;
	}
	if (_rtnFlag)
	{
		lpSceneMng.AddDrawQue({ _dbScreen, 0, 0 });
	}
	WaitMode();*/
	return true;
}

bool _DebugGraph::SetUpGraph(int alpha)
{
	/*if (_dbScreen == -1)
	{
		_dbScreen = MakeScreen(lpSceneMng.screenSize.x, lpSceneMng.screenSize.y,true);
	}
	SetAlpha(alpha);*/

	return true;
}

bool _DebugGraph::SetAlpha(int alpha)
{
	_alpha = alpha;
	return true;
}

_DebugGraph::_DebugGraph()
{
	_dbScreen = -1;
	_rtnFlag = true;
}


_DebugGraph::~_DebugGraph()
{
}

bool _DebugGraph::SetScreen(void)
{
	/*_ghBuffer = GetDrawScreen();
	SetDrawScreen(_dbScreen);*/
	return true;
}

bool _DebugGraph::RevScreen(void)
{
	//SetDrawScreen(_ghBuffer);
	return true;
}

#endif
