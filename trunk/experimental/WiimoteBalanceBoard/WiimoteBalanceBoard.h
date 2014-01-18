//
//  WiimoteBalanceBoard.h
//  WiimoteBalanceBoard
//
//  Created by alxn1 on 10.08.12.
//  Copyright 2012 alxn1. All rights reserved.
//

#import <Wiimote/Wiimote+PlugIn.h>
#import "WiimoteBalanceBoardDelegate.h"

#pragma pack(push, 1)

typedef struct
{
    uint16_t topRightPress;
    uint16_t bottomRightPress;
    uint16_t topLeftPress;
    uint16_t bottomLeftPress;
} WiimoteBalanceBoardReport;

typedef struct
{
    WiimoteBalanceBoardReport kg0;
    WiimoteBalanceBoardReport kg17;
    WiimoteBalanceBoardReport kg34;
} WiimoteBalanceBoardCalibrationData;

#pragma pack(pop)

#define WiimoteBalanceBoardCalibrationDataAddress 0x04A40024
#define WiimoteBalanceBoardCalibrationDataSize    24

@interface WiimoteBalanceBoard : WiimoteGenericExtension<
                                                WiimoteBalanceBoardProtocol>
{
    @private
        BOOL                                m_IsCalibrationDataReaded;

        double                              m_TopLeftPress;
        double                              m_TopRightPress;
        double                              m_BottomLeftPress;
        double                              m_BottomRightPress;

        WiimoteBalanceBoardCalibrationData  m_CalibrationData;
}

@end