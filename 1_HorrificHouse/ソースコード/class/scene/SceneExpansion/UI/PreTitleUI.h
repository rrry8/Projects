#pragma once
#include "TitleUI.h"
class PreTitleUI :
    public TitleUI
{
public:
	PreTitleUI();
	~PreTitleUI();
	void Init()override;
	void Update()override;
	void Draw()override;

private:
	//UIMapの初期化
	void InitUIMap();
	//クリックして当たったの
	void PutClickHit();
	//UIMap
	std::map<TitleColUI, UIObj<TitleColUI>> titleUIMap_;
	//決定当たったUI
	TitleColUI decideHitCol_;
	
};

