#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "TinyEXIF.h"

void print_all(const TinyEXIF::EXIFInfo &data){
    if(!data.ImageDescription.empty())
        std::cout << "Description.................: " << data.ImageDescription << std::endl;
    if(!data.Make.empty())
        std::cout << "manufacturers...............: " << data.Make << std::endl;
    if(!data.SerialNumber.empty())
        std::cout << "Serial number...............: " << data.SerialNumber << std::endl;
    if(!data.Model.empty())
        std::cout << "Model.......................: " << data.Model << std::endl;
    if(data.ImageWidth || data.ImageHeight)
        std::cout << "Resolution..................: " << data.ImageWidth << "x" << data.ImageHeight << std::endl;
    if(data.RelatedImageWidth || data.RelatedImageHeight)
        std::cout << "Relate resolution...........: " << data.RelatedImageWidth << "x" << data.RelatedImageHeight << std::endl;
    if(data.Orientation)
        std::cout << "Orientation.................: " << data.Orientation << std::endl;
    if(data.BitsPerSample)
        std::cout << "BitsPerSample...............: " << data.BitsPerSample << std::endl;
    if(!data.Software.empty())
        std::cout << "Software....................: " << data.Software << std::endl;
    if(!data.DateTime.empty())
        std::cout << "DateTime....................: " << data.DateTime << std::endl;
    if(!data.DateTimeOriginal.empty())
        std::cout << "DateTimeOriginal............: " << data.DateTimeOriginal << std::endl;
    if(!data.DateTimeDigitized.empty())
        std::cout << "DateTimeDigitized...........: " << data.DateTimeDigitized << std::endl;
    if(!data.SubSecTimeOriginal.empty())
        std::cout << "SubSecTimeOriginal..........: " << data.SubSecTimeOriginal << std::endl;
    if(!data.Copyright.empty())
        std::cout << "Copyright...................: " << data.Copyright << std::endl;

    std::cout << "ExposureTime................: " << std::setprecision(10) << data.ExposureTime << std::endl;
    std::cout << "FNumber.....................: " << data.FNumber << std::endl;
    std::cout << "ExposureProgram.............: " << data.ExposureProgram << std::endl;
    std::cout << "ISOSpeed....................: " << data.ISOSpeedRatings << std::endl;
    std::cout << "ShutterSpeedValue...........: " << std::setprecision(10) << data.ShutterSpeedValue << std::endl;
    std::cout << "ApertureValue...............: " << std::setprecision(10) << data.ApertureValue << std::endl;
    std::cout << "BrightnessValue.............: " << std::setprecision(10) << data.BrightnessValue << std::endl;
    std::cout << "ExposureBiasValue...........: " << data.ExposureBiasValue << std::endl;
    std::cout << "SubjectDistance.............: " << data.SubjectDistance << std::endl;
    std::cout << "FocalLength.................: " << data.FocalLength << " mm" << std::endl;
    std::cout << "Flash.......................: " << data.Flash << std::endl;

    if(!data.SubjectArea.empty()){
        std::cout << "SubjectArea.................: ";
		for (uint16_t val: data.SubjectArea)
			std::cout << val;
		std::cout << std::endl;
    }

	std::cout << "MeteringMode................: " << data.MeteringMode << std::endl;
	std::cout << "LightSource.................: " << data.LightSource << std::endl;
	std::cout << "ProjectionType..............: " << data.ProjectionType << std::endl;
	if(data.Calibration.FocalLength != 0)
        std::cout << "CalibrationFocalLength......: " << data.Calibration.FocalLength << std::endl;
    if(data.Calibration.OpticalCenterX != 0)
        std::cout << "CalibrationOpticalCenterX...: " << data.Calibration.OpticalCenterX << std::endl;
    if(data.Calibration.OpticalCenterY != 0)
        std::cout << "CalibrationOpticalCenterY...: " << data.Calibration.OpticalCenterY << std::endl;
	std::cout << "FStopMin....................: " << data.LensInfo.FStopMin << std::endl;
	std::cout << "FStopMax....................: " << data.LensInfo.FStopMax << std::endl;
	std::cout << "FocalLengthMin..............: " << data.LensInfo.FocalLengthMin << " mm" << std::endl;
	std::cout << "FocalLengthMax..............: " << data.LensInfo.FocalLengthMax << " mm" << std::endl;
	std::cout << "DigitalZoomRatio............: " << data.LensInfo.DigitalZoomRatio << std::endl;
	std::cout << "FocalLengthIn35mm...........: " << data.LensInfo.FocalLengthIn35mm << std::endl;
	std::cout << "FocalPlaneXResolution.......: " << std::setprecision(10) << data.LensInfo.FocalPlaneXResolution << std::endl;
	std::cout << "FocalPlaneYResolution.......: " << std::setprecision(10) << data.LensInfo.FocalPlaneYResolution << std::endl;
	std::cout << "FocalPlaneResolutionUnit....: " << data.LensInfo.FocalPlaneResolutionUnit << std::endl;

	if(!data.LensInfo.Make.empty() || !data.LensInfo.Model.empty())
        std::cout << "LensInfoModel...............: " << data.LensInfo.Make << "-" << data.LensInfo.Model << std::endl;

    if(data.GeoLocation.hasLatLon()){
        std::cout << "Latitude....................: " << std::setprecision(10) << data.GeoLocation.Latitude << std::endl;
        std::cout << "Longitude...................: " << std::setprecision(10) << data.GeoLocation.Longitude << std::endl;
    }

    if(data.GeoLocation.hasAltitude()){
        std::cout << "Altitude....................: " << data.GeoLocation.Altitude << " m" << std::endl;
        std::cout << "AltitudeRef.................: " << (int)data.GeoLocation.AltitudeRef << std::endl;
    }

    if(data.GeoLocation.hasRelativeAltitude())
        std::cout << "RelativeAltitude............: " << data.GeoLocation.RelativeAltitude << " m" << std::endl;

    if(data.GeoLocation.hasOrientation()){
        std::cout << "RollDegree..................: " << data.GeoLocation.RollDegree << std::endl;
        std::cout << "PitchDegree.................: " << data.GeoLocation.PitchDegree << std::endl;
        std::cout << "YawDegree...................: " << data.GeoLocation.YawDegree << std::endl;
    }

    if(data.GeoLocation.hasSpeed()){
        std::cout << "SpeedX......................: " << data.GeoLocation.SpeedX << " m/s" << std::endl;
        std::cout << "SpeedY......................: " << data.GeoLocation.SpeedY << " m/s" << std::endl;
        std::cout << "SpeedZ......................: " << data.GeoLocation.SpeedZ << " m/s" << std::endl;
    }

    if((data.GeoLocation.AccuracyXY > 0) || (data.GeoLocation.AccuracyZ > 0))
        std::cout << "GPSAccuracy XY..............: " << data.GeoLocation.AccuracyXY << " m" << " Z " << data.GeoLocation.AccuracyZ << " m" << std::endl;

	std::cout << "GPSDOP......................: " << data.GeoLocation.GPSDOP << std::endl;
    std::cout << "GPSDifferential.............: " << data.GeoLocation.GPSDifferential << std::endl;

	if(!data.GeoLocation.GPSMapDatum.empty())
        std::cout << "GPSMapDatum.................: " << data.GeoLocation.GPSMapDatum << std::endl;

	if(!data.GeoLocation.GPSTimeStamp.empty())
        std::cout << "GPSTimeStamp................: " << data.GeoLocation.GPSTimeStamp << std::endl;

	if(!data.GeoLocation.GPSDateStamp.empty())
        std::cout << "GPSDateStamp................: " << data.GeoLocation.GPSDateStamp << std::endl;

	if(data.GPano.hasPosePitchDegrees())
        std::cout << "PosePitchDegrees............: " << data.GPano.PosePitchDegrees << std::endl;

	if(data.GPano.hasPoseRollDegrees())
        std::cout << "PoseRollDegrees.............: " << data.GPano.PoseRollDegrees << std::endl;
}

int main(int argc, const char** argv){
    if(argc == 2){
        std::ifstream file(argv[1], std::ios::binary);
        if(file.is_open()){
            TinyEXIF::EXIFInfo image(file);
            if(image.Fields)
                print_all(image);
            else
                std::cerr << "Not EXIF metadata!" << std::endl;
            file.close();
        }
        else
            std::cerr << "File not open!" << std::endl;
    }
    else
        std::cout << "Usage: exifdata [filename]" << std::endl;
	return 0;
}
