#include "MoveCtl.h"
#include "unit/Obj.h"
#include "MojuleHeader.h"

void MoveCtl::AddActMojule(std::string actName, ActMojule & act)
{
	if (_actList.find(actName) == _actList.end())
	{
		_actList.emplace(actName, act);
		if (_actList.at(actName).action != nullptr)
		{
			_actList.at(actName).action->retain();
		}
	}
}

//void MoveCtl::ActUpdate(cocos2d::Sprite & sp, ActMojule& actData)
//{
//	auto checkList = [&](){
//		for (auto list: actData.actionList)
//		{
//			if (!list)
//			{
//				return false;
//			}
//		}
//		return true;
//	};
//	
//	for (auto act : actData.actionList)
//	{
//		if (checkList())
//		{
//			actData.runAction(sp, actData);
//		}
//	}
//
//}

bool MoveCtl::SetActState(cocos2d::Sprite& sp, std::weak_ptr<OPRT> oprt)
{
	_actList.at(((Obj&)sp).stateName()).runAction(sp, _actList.at(((Obj&)sp).stateName()));

	//キーの入力情報から追加するモジュールを全走査
	for (auto keyData : oprt.lock()->key())
	{
		for (auto act : _actList)
		{
			if (act.second.keyData == keyData)
			{
				if (CheckList()(sp,act.second))
				{
					act.second.runAction(sp, act.second);
					if (act.second.action != nullptr && !act.second.repeat)
					{
						//sp.stopAllActions();
						lpAnimCtl.runAction(sp, act.second);
						//sp.runAction(act.second.action);
					}
				}
			}
		}
	}

	return true;
}

ActMojule MoveCtl::GetActData(const std::string& actName)
{
	return _actList.at(actName);
}

MoveCtl::~MoveCtl()
{
	for (auto data : _actList)
	{
		if (data.second.action != nullptr)
		{
			data.second.action->release();
		}
	}
}
