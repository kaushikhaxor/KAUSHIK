if (Config.Mrkaushikhaxor.Vehicle) {
                        if (Actors[i]->IsA(ASTExtraVehicleBase::StaticClass())) {
       auto Vehicle = (ASTExtraVehicleBase *)Actors[i];
       if (!Vehicle->Mesh)
        continue;

       int CurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->HP, (int) Vehicle->VehicleCommon->HPMax));
       int sCurHP = (int) std::max(0, std::min((int) Vehicle->VehicleCommon->Fuel, (int) Vehicle->VehicleCommon->FuelMax));
       int MaxHP = (int) Vehicle->VehicleCommon->HPMax;
       int sMaxHP = (int) Vehicle->VehicleCommon->FuelMax;
       float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.0f;
       if (Distance <= 300.0f) {
        FVector2D vehiclePos;
        if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos)) {
         auto mWidthScale = std::min(00.0f * Distance, 50.0f);
         auto mWidth = 70.0f - mWidthScale;
         auto mHeight = mWidth * 0.10f;
         auto smWidth = 70.0f - mWidthScale;
         auto smHeight = smWidth * 0.10f;
            if (Config.Mrkaushikhaxor.Vehicle) {
          std::string s = GetVehicleName(Vehicle);
          s += " - ";
          s += std::to_string((int)Distance);
          s += "M";
          auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 30.0f));
          draw->AddText(Injector, ((float) density / 30.0f), {vehiclePos.X - (mWidth / 2), vehiclePos.Y - 40}, IM_COL32(255, 255, 255, 255), s.c_str());
         }
            if (Config.Mrkaushikhaxor.Vehicle) {
          ImVec2 vStart = {vehiclePos.X - (smWidth / 2), vehiclePos.Y - (smHeight * 1.75f)};
          ImVec2 vEndFilled = {vStart.x + (sCurHP * smWidth / sMaxHP), vStart.y + smHeight};
          draw->AddRectFilled(vStart, vEndFilled, IM_COL32(200, 200, 0, 200), 0.0f, 240);
          draw->AddRect(vStart, vEndFilled, IM_COL32(255, 255, 255, 255), 0.0f, 240);
         }
            if (Config.Mrkaushikhaxor.Vehicle) {
          ImVec2 vStart = {vehiclePos.X - (mWidth / 2), vehiclePos.Y - (mHeight * 3.00f)};
          ImVec2 vEndFilled = {vStart.x + (CurHP * mWidth / MaxHP), vStart.y + mHeight};
          draw->AddRectFilled(vStart, vEndFilled, IM_COL32(200, 0, 0, 200), 0.0f, 240);
          draw->AddRect(vStart, vEndFilled, IM_COL32(255, 255, 255, 255), 0.0f, 240);
         }
        }
       }
      }
     }