
extern bool bunny_hop;
extern bool auto_strafe;
extern bool infinite_duck;
extern bool edge_jump;


void Bunnyhop()
{
    static bool last_jumped = false;
    static bool should_fake = false;

    if (!bunny_hop)
        return;

    if (Data::localPlayer)
    {
        if (Data::localPlayer->CharacterMovement && Data::localPlayer->CharacterMovement->IsMovingOnGround())
        {
            Data::localPlayer->Jump();
            FVector NewVelocity = Data::localPlayer->GetVelocity();
            NewVelocity.X += 100.0f; // Tăng tốc độ (có thể điều chỉnh theo nhu cầu)
            Data::localPlayer->LaunchCharacter(NewVelocity, true, true);

            last_jumped = true;
            should_fake = true;
        }
        else
        {
            Data::localPlayer->bPressedJump = false;
            last_jumped = false;
            should_fake = false;
        }
    }
    else
    {
        last_jumped = false;
        should_fake = false;
    }
}

void AutoStrafe()
{
    // Kiểm tra nếu tính năng AutoStrafe được bật
    if (!auto_strafe)
        return;

    if (Data::localPlayer && Data::localPlayer->IsAlive())  // Kiểm tra nếu nhân vật đang sống
    {
        // Kiểm tra nếu không phải đang di chuyển trên mặt đất
        if (Data::localPlayer->CharacterMovement->MovementMode != EMovementMode::MOVE_Walking)  // Không phải di chuyển bình thường
            return;

        if (Data::localPlayer->GetVelocity().Z == 0.0f)  // Nếu không rơi xuống đất
            return;

        FVector velocity = Data::localPlayer->GetVelocity();
        velocity.Z = 0.0f;  // Loại bỏ thành phần Z của tốc độ để chỉ tính tốc độ trên mặt đất

        float speed = UKismetMathLibrary::Sqrt(UKismetMathLibrary::Square(velocity.X) + UKismetMathLibrary::Square(velocity.Y));  // Tính tốc độ 2D

        // Nếu tốc độ quá thấp hoặc không có lệnh di chuyển, không làm gì
        if (speed < 5.0f)
            return;

        // Cập nhật góc quay của nhân vật
        FRotator viewRotation = Data::localPlayer->GetControlRotation();
        float currentYaw = viewRotation.Yaw;

        // Tính toán góc di chuyển dựa trên hướng di chuyển
        static bool flip = false;
        flip = !flip;  // Chuyển đổi góc quay để tạo hiệu ứng AutoStrafe

        float turnDirectionModifier = flip ? 1.0f : -1.0f;

        FVector forward = Data::localPlayer->GetActorForwardVector();
        FVector right = Data::localPlayer->GetActorRightVector();

        // Lấy các giá trị move của người chơi
        float forwardMove = Data::localPlayer->GetInputAxisValue("MoveForward");
        float sideMove = Data::localPlayer->GetInputAxisValue("MoveRight");

        // Cập nhật các hướng di chuyển
        if (forwardMove != 0.0f || sideMove != 0.0f)
        {
            Data::localPlayer->AddMovementInput(forward, 0.0f, false);  // Không di chuyển về phía trước
            Data::localPlayer->AddMovementInput(right, sideMove, false);  // Thực hiện strafe sang trái/phải
        }
        
        // Tính toán góc quay của nhân vật
        float strafeAngle = UKismetMathLibrary::RadiansToDegrees(UKismetMathLibrary::Atan2(15.0f, speed));
        if (strafeAngle > 90.0f)
            strafeAngle = 90.0f;
        else if (strafeAngle < 0.0f)
            strafeAngle = 0.0f;

        // Tính toán góc mới cho yaw
        viewRotation.Yaw += strafeAngle * turnDirectionModifier;
        Data::localPlayer->K2_SetActorRotation(viewRotation, true);  // Cập nhật góc quay cho nhân vật

        // Cập nhật lệnh di chuyển (sidemove)
        FVector moveDirection = Data::localPlayer->GetVelocity();
        moveDirection.Z = 0.0f;  // Chỉ quan tâm đến di chuyển ngang

        // Tính tốc độ di chuyển ngang
        float moveSpeed = UKismetMathLibrary::Sqrt(UKismetMathLibrary::Square(moveDirection.X) + UKismetMathLibrary::Square(moveDirection.Y));  

        if (moveSpeed > 0.0f)
        {
            // Normalize the direction manually
            if (moveSpeed != 0.0f)  // Avoid division by zero
            {
                FVector newMoveDirection = moveDirection / moveSpeed;  // Normalize direction manually
                Data::localPlayer->AddMovementInput(newMoveDirection, moveSpeed, false);  // Cập nhật lệnh di chuyển
            }
        }
    }
}
void InfiniteDuck()
{
    // Kiểm tra nếu tính năng Infinite Duck được bật
    if (!infinite_duck)
        return;
    
    if (Data::localPlayer && Data::localPlayer->IsAlive())  // Kiểm tra nếu nhân vật đang sống
    {
        Data::localPlayer->OnRep_IsCrouched();
        // Kiểm tra nếu nhân vật đang cúi
        bool isCrouched = Data::localPlayer->bIsCrouched;  // Kiểm tra trạng thái cúi của nhân vật (giả sử bIsCrouched là một thuộc tính bool)

        if (!isCrouched)  // Nếu nhân vật chưa cúi
        {
            // Thực hiện cúi nhân vật
            Data::localPlayer->Crouch(true);  // Thêm tham số true cho bClientSimulation
        }

    }
}
void EdgeJump()
{
    // Kiểm tra nếu tính năng EdgeJump được bật
    if (!edge_jump)
        return;

    if (Data::localPlayer && Data::localPlayer->IsAlive())  // Kiểm tra nếu nhân vật đang sống
    {
        // Lấy vị trí hiện tại của nhân vật
        FVector playerLocation = Data::localPlayer->K2_GetActorLocation();

        // Lấy hướng di chuyển của nhân vật
        FVector forwardVector = Data::localPlayer->GetActorForwardVector();

        // Kiểm tra xem nhân vật có đang đứng gần mép
        FVector traceStart = playerLocation;  // Vị trí bắt đầu raycast
        FVector traceEnd = playerLocation + forwardVector * 100.0f;  // Vị trí kết thúc raycast, mở rộng từ nhân vật về phía trước

        // Khởi tạo các tham số cho va chạm
        FVector hitLocation;
        FVector hitNormal;
        FName boneName;
        FHitResult hitResult;

        // Thực hiện raycast bằng K2_LineTraceComponent
      //  bool hit = GetFullWorld()->LineBatcher->K2_LineTraceComponent(traceStart, traceEnd, true, true, &hitLocation, &hitNormal, &boneName, &hitResult);
/*
        if (hit)  // Nếu có va chạm
        {
            // Kiểm tra nếu mặt phẳng va chạm gần với bề mặt ngang (Z thấp)
            if (hitNormal.Z < 0.5f)  // Nếu mặt phẳng va chạm nghiêng
            {
                // Thực hiện nhảy khi đứng gần mép
                Data::localPlayer->Jump();  // Giả sử Jump() là phương thức nhảy của nhân vật
            }
        }
        */
    }
}

void AdjustPitchDown()
{
    if (Data::localPlayer && Data::localPlayer->IsAlive()) 
    {
        FRotator CurrentRotation = Data::localPlayer->K2_GetActorRotation();
        CurrentRotation.Pitch = UKismetMathLibrary::Clamp(CurrentRotation.Pitch - 10.0f, -90.0f, 0.0f);
        Data::localPlayer->K2_SetActorRotation(CurrentRotation, true);
    }
}

void AdjustYawBackward()
{
     if (Data::localPlayer && Data::localPlayer->IsAlive()) 
    {
        FRotator CurrentRotation = Data::localPlayer->K2_GetActorRotation();
        CurrentRotation.Yaw = UKismetMathLibrary::Clamp(CurrentRotation.Yaw + 180.0f, -180.0f, 180.0f);
        Data::localPlayer->K2_SetActorRotation(CurrentRotation, true);
    }
}

void ApplyYawJitter()
{
    if (Data::localPlayer && Data::localPlayer->IsAlive()) 
    {
        FRotator CurrentRotation = Data::localPlayer->K2_GetActorRotation();
        float JitterAmount = UKismetMathLibrary::RandomFloatInRange(-5.0f, 5.0f); // Giá trị jitter ngẫu nhiên
        CurrentRotation.Yaw += JitterAmount;
        Data::localPlayer->K2_SetActorRotation(CurrentRotation, true);
    }
}

void AntiAim()
{
    if (Data::localPlayer && Data::localPlayer->IsAlive()) 
    {
   
        AdjustPitchDown();
        AdjustYawBackward();
        ApplyYawJitter();
    }
}

