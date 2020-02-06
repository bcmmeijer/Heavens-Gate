#include <iostream>
#include <fstream>


enum syscalls {
	NtAcceptConnectPort = 0x2,
	NtAccessCheck = 0x0,
	NtAccessCheckAndAuditAlarm = 0x29,
	NtAccessCheckByType = 0x63,
	NtAccessCheckByTypeAndAuditAlarm = 0x59,
	NtAccessCheckByTypeResultList = 0x64,
	NtAccessCheckByTypeResultListAndAuditAlarm = 0x65,
	NtAccessCheckByTypeResultListAndAuditAlarmByHandle = 0x66,
	NtAddAtom = 0x47,
	NtAddBootEntry = 0x6a,
	NtAddDriverEntry = 0x6b,
	NtAdjustGroupsToken = 0x6c,
	NtAdjustPrivilegesToken = 0x41,
	NtAlertResumeThread = 0x6e,
	NtAlertThread = 0x6f,
	NtAllocateLocallyUniqueId = 0x71,
	NtAllocateUserPhysicalPages = 0x73,
	NtAllocateUuids = 0x75,
	NtAllocateVirtualMemory = 0x18,
	NtApphelpCacheControl = 0x4c,
	NtAreMappedFilesTheSame = 0x8e,
	NtAssignProcessToJobObject = 0x8f,
	NtCallbackReturn = 0x5,
	NtCancelIoFile = 0x5d,
	NtCancelTimer = 0x61,
	NtClearEvent = 0x3e,
	NtClose = 0xf,
	NtCloseObjectAuditAlarm = 0x3b,
	NtCompactKeys = 0x9a,
	NtCompareTokens = 0x9d,
	NtCompleteConnectPort = 0x9e,
	NtCompressKey = 0x9f,
	NtConnectPort = 0xa0,
	NtContinue = 0x43,
	NtCreateDebugObject = 0xa5,
	NtCreateDirectoryObject = 0xa6,
	NtCreateEvent = 0x48,
	NtCreateEventPair = 0xaa,
	NtCreateFile = 0x55,
	NtCreateIoCompletion = 0xac,
	NtCreateJobObject = 0xad,
	NtCreateJobSet = 0xae,
	NtCreateKey = 0x1d,
	NtCreateKeyedEvent = 0xb0,
	NtCreateMailslotFile = 0xb2,
	NtCreateMutant = 0xb3,
	NtCreateNamedPipeFile = 0xb4,
	NtCreatePagingFile = 0xb5,
	NtCreatePort = 0xb7,
	NtCreateProcess = 0xb9,
	NtCreateProcessEx = 0x4d,
	NtCreateProfile = 0xba,
	NtCreateSection = 0x4a,
	NtCreateSemaphore = 0xbf,
	NtCreateSymbolicLinkObject = 0xc0,
	NtCreateThread = 0x4e,
	NtCreateTimer = 0xc2,
	NtCreateToken = 0xc4,
	NtCreateWaitablePort = 0xca,
	NtDebugActiveProcess = 0xcd,
	NtDebugContinue = 0xce,
	NtDelayExecution = 0x34,
	NtDeleteAtom = 0xcf,
	NtDeleteBootEntry = 0xd0,
	NtDeleteDriverEntry = 0xd1,
	NtDeleteFile = 0xd2,
	NtDeleteKey = 0xd3,
	NtDeleteObjectAuditAlarm = 0xd4,
	NtDeleteValueKey = 0xd6,
	NtDeviceIoControlFile = 0x7,
	NtDisplayString = 0xdb,
	NtDuplicateObject = 0x3c,
	NtDuplicateToken = 0x42,
	NtEnumerateBootEntries = 0xde,
	NtEnumerateDriverEntries = 0xdf,
	NtEnumerateKey = 0x32,
	NtEnumerateSystemEnvironmentValuesEx = 0xe0,
	NtEnumerateValueKey = 0x13,
	NtExtendSection = 0xe2,
	NtFilterToken = 0xe4,
	NtFindAtom = 0x14,
	NtFlushBuffersFile = 0x4b,
	NtFlushInstructionCache = 0xe8,
	NtFlushKey = 0xe9,
	NtFlushVirtualMemory = 0xeb,
	NtFlushWriteBuffer = 0xec,
	NtFreeUserPhysicalPages = 0xed,
	NtFreeVirtualMemory = 0x1e,
	NtFsControlFile = 0x39,
	NtGetContextThread = 0xf2,
	NtGetCurrentProcessorNumber = 0xf3,
	NtGetDevicePowerState = 0xf5,
	NtGetWriteWatch = 0xfb,
	NtImpersonateAnonymousToken = 0xfc,
	NtImpersonateClientOfPort = 0x1f,
	NtImpersonateThread = 0xfd,
	NtInitializeRegistry = 0x100,
	NtInitiatePowerAction = 0x101,
	NtIsProcessInJob = 0x4f,
	NtIsSystemResumeAutomatic = 0x102,
	NtListenPort = 0x104,
	NtLoadDriver = 0x105,
	NtLoadKey = 0x107,
	NtLoadKey2 = 0x108,
	NtLoadKeyEx = 0x109,
	NtLockFile = 0x10a,
	NtLockProductActivationKeys = 0x10b,
	NtLockRegistryKey = 0x10c,
	NtLockVirtualMemory = 0x10d,
	NtMakePermanentObject = 0x10e,
	NtMakeTemporaryObject = 0x10f,
	NtMapUserPhysicalPages = 0x113,
	NtMapUserPhysicalPagesScatter = 0x3,
	NtMapViewOfSection = 0x28,
	NtModifyBootEntry = 0x115,
	NtModifyDriverEntry = 0x116,
	NtNotifyChangeDirectoryFile = 0x117,
	NtNotifyChangeKey = 0x119,
	NtNotifyChangeMultipleKeys = 0x11a,
	NtOpenDirectoryObject = 0x58,
	NtOpenEvent = 0x40,
	NtOpenEventPair = 0x11d,
	NtOpenFile = 0x33,
	NtOpenIoCompletion = 0x11e,
	NtOpenJobObject = 0x11f,
	NtOpenKey = 0x12,
	NtOpenKeyedEvent = 0x123,
	NtOpenMutant = 0x124,
	NtOpenObjectAuditAlarm = 0x125,
	NtOpenProcess = 0x26,
	NtOpenProcessToken = 0x128,
	NtOpenProcessTokenEx = 0x30,
	NtOpenSection = 0x37,
	NtOpenSemaphore = 0x12b,
	NtOpenSymbolicLinkObject = 0x12d,
	NtOpenThread = 0x12e,
	NtOpenThreadToken = 0x24,
	NtOpenThreadTokenEx = 0x2f,
	NtOpenTimer = 0x12f,
	NtPlugPlayControl = 0x132,
	NtPowerInformation = 0x5f,
	NtPrivilegeCheck = 0x137,
	NtPrivilegedServiceAuditAlarm = 0x139,
	NtPrivilegeObjectAuditAlarm = 0x138,
	NtProtectVirtualMemory = 0x50,
	NtPulseEvent = 0x13d,
	NtQueryAttributesFile = 0x3d,
	NtQueryBootEntryOrder = 0x13f,
	NtQueryBootOptions = 0x140,
	NtQueryDebugFilterState = 0x141,
	NtQueryDefaultLocale = 0x15,
	NtQueryDefaultUILanguage = 0x44,
	NtQueryDirectoryFile = 0x35,
	NtQueryDirectoryObject = 0x143,
	NtQueryDriverEntryOrder = 0x144,
	NtQueryEaFile = 0x145,
	NtQueryEvent = 0x56,
	NtQueryFullAttributesFile = 0x146,
	NtQueryInformationAtom = 0x147,
	NtQueryInformationFile = 0x11,
	NtQueryInformationJobObject = 0x14a,
	NtQueryInformationPort = 0x14b,
	NtQueryInformationProcess = 0x19,
	NtQueryInformationThread = 0x25,
	NtQueryInformationToken = 0x21,
	NtQueryInstallUILanguage = 0x150,
	NtQueryIntervalProfile = 0x151,
	NtQueryIoCompletion = 0x152,
	NtQueryKey = 0x16,
	NtQueryMultipleValueKey = 0x154,
	NtQueryMutant = 0x155,
	NtQueryObject = 0x10,
	NtQueryOpenSubKeys = 0x156,
	NtQueryOpenSubKeysEx = 0x157,
	NtQueryPerformanceCounter = 0x31,
	NtQueryPortInformationProcess = 0x158,
	NtQueryQuotaInformationFile = 0x159,
	NtQuerySection = 0x51,
	NtQuerySecurityObject = 0x15b,
	NtQuerySemaphore = 0x15d,
	NtQuerySymbolicLinkObject = 0x15e,
	NtQuerySystemEnvironmentValue = 0x15f,
	NtQuerySystemEnvironmentValueEx = 0x160,
	NtQuerySystemInformation = 0x36,
	NtQueryTimer = 0x38,
	NtQueryTimerResolution = 0x162,
	NtQueryValueKey = 0x17,
	NtQueryVirtualMemory = 0x23,
	NtQueryVolumeInformationFile = 0x49,
	NtQueueApcThread = 0x45,
	NtRaiseException = 0x166,
	NtRaiseHardError = 0x167,
	NtReadFile = 0x6,
	NtReadFileScatter = 0x2e,
	NtReadRequestData = 0x54,
	NtReadVirtualMemory = 0x3f,
	NtRegisterThreadTerminatePort = 0x16d,
	NtReleaseKeyedEvent = 0x16e,
	NtReleaseMutant = 0x20,
	NtReleaseSemaphore = 0xa,
	NtRemoveIoCompletion = 0x9,
	NtRemoveProcessDebug = 0x171,
	NtRenameKey = 0x172,
	NtReplaceKey = 0x174,
	NtReplyPort = 0xc,
	NtReplyWaitReceivePort = 0xb,
	NtReplyWaitReceivePortEx = 0x2b,
	NtReplyWaitReplyPort = 0x176,
	NtRequestPort = 0x177,
	NtRequestWaitReplyPort = 0x22,
	NtResetEvent = 0x178,
	NtResetWriteWatch = 0x179,
	NtRestoreKey = 0x17a,
	NtResumeProcess = 0x17b,
	NtResumeThread = 0x52,
	NtSaveKey = 0x182,
	NtSaveKeyEx = 0x183,
	NtSaveMergedKeys = 0x184,
	NtSecureConnectPort = 0x185,
	NtSetBootEntryOrder = 0x187,
	NtSetBootOptions = 0x188,
	NtSetContextThread = 0x18b,
	NtSetDebugFilterState = 0x18c,
	NtSetDefaultHardErrorPort = 0x18d,
	NtSetDefaultLocale = 0x18e,
	NtSetDefaultUILanguage = 0x18f,
	NtSetDriverEntryOrder = 0x190,
	NtSetEaFile = 0x191,
	NtSetEvent = 0xe,
	NtSetEventBoostPriority = 0x2d,
	NtSetHighEventPair = 0x192,
	NtSetHighWaitLowEventPair = 0x193,
	NtSetInformationDebugObject = 0x195,
	NtSetInformationFile = 0x27,
	NtSetInformationJobObject = 0x197,
	NtSetInformationKey = 0x198,
	NtSetInformationObject = 0x5c,
	NtSetInformationProcess = 0x1c,
	NtSetInformationThread = 0xd,
	NtSetInformationToken = 0x19b,
	NtSetIntervalProfile = 0x1a0,
	NtSetIoCompletion = 0x1a1,
	NtSetLdtEntries = 0x1a3,
	NtSetLowEventPair = 0x1a4,
	NtSetLowWaitHighEventPair = 0x1a5,
	NtSetQuotaInformationFile = 0x1a6,
	NtSetSecurityObject = 0x1a7,
	NtSetSystemEnvironmentValue = 0x1a8,
	NtSetSystemEnvironmentValueEx = 0x1a9,
	NtSetSystemInformation = 0x1aa,
	NtSetSystemPowerState = 0x1ab,
	NtSetSystemTime = 0x1ac,
	NtSetThreadExecutionState = 0x1ad,
	NtSetTimer = 0x62,
	NtSetTimerResolution = 0x1b0,
	NtSetUuidSeed = 0x1b1,
	NtSetValueKey = 0x60,
	NtSetVolumeInformationFile = 0x1b2,
	NtShutdownSystem = 0x1b4,
	NtSignalAndWaitForSingleObject = 0x1b6,
	NtStartProfile = 0x1b8,
	NtStopProfile = 0x1b9,
	NtSuspendProcess = 0x1bb,
	NtSuspendThread = 0x1bc,
	NtSystemDebugControl = 0x1bd,
	NtTerminateJobObject = 0x1bf,
	NtTerminateProcess = 0x2c,
	NtTerminateThread = 0x53,
	NtTestAlert = 0x1c0,
	NtTraceEvent = 0x5e,
	NtTranslateFilePath = 0x1c4,
	NtUnloadDriver = 0x1c6,
	NtUnloadKey = 0x1c7,
	NtUnloadKey2 = 0x1c8,
	NtUnloadKeyEx = 0x1c9,
	NtUnlockFile = 0x1ca,
	NtUnlockVirtualMemory = 0x1cb,
	NtUnmapViewOfSection = 0x2a,
	NtVdmControl = 0x1cf,
	NtWaitForDebugEvent = 0x1d1,
	NtWaitForKeyedEvent = 0x1d2,
	NtWaitForMultipleObjects = 0x5b,
	NtWaitForMultipleObjects32 = 0x1a,
	NtWaitForSingleObject = 0x4,
	NtWaitHighEventPair = 0x1d4,
	NtWaitLowEventPair = 0x1d5,
	NtWriteFile = 0x8,
	NtWriteFileGather = 0x1b,
	NtWriteRequestData = 0x57,
	NtWriteVirtualMemory = 0x3a,
	NtYieldExecution = 0x46,
	NtAlpcAcceptConnectPort = 0x77,
	NtAlpcCancelMessage = 0x78,
	NtAlpcConnectPort = 0x79,
	NtAlpcCreatePort = 0x7b,
	NtAlpcCreatePortSection = 0x7c,
	NtAlpcCreateResourceReserve = 0x7d,
	NtAlpcCreateSectionView = 0x7e,
	NtAlpcCreateSecurityContext = 0x7f,
	NtAlpcDeletePortSection = 0x80,
	NtAlpcDeleteResourceReserve = 0x81,
	NtAlpcDeleteSectionView = 0x82,
	NtAlpcDeleteSecurityContext = 0x83,
	NtAlpcDisconnectPort = 0x84,
	NtAlpcImpersonateClientOfPort = 0x86,
	NtAlpcOpenSenderProcess = 0x87,
	NtAlpcOpenSenderThread = 0x88,
	NtAlpcQueryInformation = 0x89,
	NtAlpcQueryInformationMessage = 0x8a,
	NtAlpcRevokeSecurityContext = 0x8b,
	NtAlpcSendWaitReceivePort = 0x8c,
	NtAlpcSetInformation = 0x8d,
	NtCancelIoFileEx = 0x92,
	NtCancelSynchronousIoFile = 0x93,
	NtCommitComplete = 0x96,
	NtCommitEnlistment = 0x97,
	NtCommitTransaction = 0x99,
	NtCreateEnlistment = 0xa9,
	NtCreateKeyTransacted = 0xaf,
	NtCreatePrivateNamespace = 0xb8,
	NtCreateResourceManager = 0xbd,
	NtCreateThreadEx = 0xc1,
	NtCreateTransaction = 0xc6,
	NtCreateTransactionManager = 0xc7,
	NtCreateUserProcess = 0xc8,
	NtCreateWorkerFactory = 0xcc,
	NtDeletePrivateNamespace = 0xd5,
	NtEnumerateTransactionObject = 0xe1,
	NtFlushInstallUILanguage = 0xe7,
	NtFlushProcessWriteBuffers = 0xea,
	NtFreezeRegistry = 0xee,
	NtFreezeTransactions = 0xef,
	NtGetMUIRegistryInfo = 0xf6,
	NtGetNextProcess = 0xf7,
	NtGetNextThread = 0xf8,
	NtGetNlsSectionPtr = 0xf9,
	NtGetNotificationResourceManager = 0xfa,
	NtInitializeNlsFiles = 0xff,
	NtIsUILanguageComitted = 0x103,
	NtMapCMFModule = 0x112,
	NtOpenEnlistment = 0x11c,
	NtOpenKeyTransacted = 0x121,
	NtOpenPrivateNamespace = 0x127,
	NtOpenResourceManager = 0x12a,
	NtOpenSession = 0x12c,
	NtOpenTransaction = 0x130,
	NtOpenTransactionManager = 0x131,
	NtPrepareComplete = 0x135,
	NtPrepareEnlistment = 0x136,
	NtPrePrepareComplete = 0x133,
	NtPrePrepareEnlistment = 0x134,
	NtPropagationComplete = 0x13a,
	NtPropagationFailed = 0x13b,
	NtQueryInformationEnlistment = 0x149,
	NtQueryInformationResourceManager = 0x14c,
	NtQueryInformationTransaction = 0x14d,
	NtQueryInformationTransactionManager = 0x14e,
	NtQueryInformationWorkerFactory = 0x14f,
	NtQueryLicenseValue = 0x153,
	NtReadOnlyEnlistment = 0x168,
	NtRecoverEnlistment = 0x169,
	NtRecoverResourceManager = 0x16a,
	NtRecoverTransactionManager = 0x16b,
	NtRegisterProtocolAddressInformation = 0x16c,
	NtReleaseWorkerFactoryWorker = 0x16f,
	NtRemoveIoCompletionEx = 0x170,
	NtRollbackComplete = 0x17d,
	NtRollbackEnlistment = 0x17e,
	NtRollbackTransaction = 0x180,
	NtRollforwardTransactionManager = 0x181,
	NtSetInformationEnlistment = 0x196,
	NtSetInformationResourceManager = 0x199,
	NtSetInformationTransaction = 0x19c,
	NtSetInformationTransactionManager = 0x19d,
	NtSetInformationWorkerFactory = 0x19f,
	NtShutdownWorkerFactory = 0x1b5,
	NtSinglePhaseReject = 0x1b7,
	NtThawRegistry = 0x1c1,
	NtThawTransactions = 0x1c2,
	NtTraceControl = 0x1c3,
	NtWaitForWorkViaWorkerFactory = 0x1d3,
	NtWorkerFactoryWorkerReady = 0x1,
	NtRenameTransactionManager = 0x173,
	NtReplacePartitionUnit = 0x175,
	NtAllocateReserveObject = 0x72,
	NtCreateProfileEx = 0xbb,
	NtDisableLastKnownGood = 0xda,
	NtDrawText = 0xdc,
	NtEnableLastKnownGood = 0xdd,
	NtNotifyChangeSession = 0x11b,
	NtOpenKeyEx = 0x120,
	NtOpenKeyTransactedEx = 0x122,
	NtQuerySecurityAttributesToken = 0x15a,
	NtQuerySystemInformationEx = 0x161,
	NtQueueApcThreadEx = 0x165,
	NtSerializeBoot = 0x186,
	NtSetIoCompletionEx = 0x1a2,
	NtSetTimerEx = 0x1af,
	NtUmsThreadYield = 0x1c5,
	NtAddAtomEx = 0x69,
	NtAdjustTokenClaimsAndDeviceGroups = 0x6d,
	NtAlertThreadByThreadId = 0x70,
	NtAlpcConnectPortEx = 0x7a,
	NtAssociateWaitCompletionPacket = 0x90,
	NtCancelWaitCompletionPacket = 0x95,
	NtCreateDirectoryObjectEx = 0xa7,
	NtCreateIRTimer = 0xab,
	NtCreateLowBoxToken = 0xb1,
	NtCreateTokenEx = 0xc5,
	NtCreateWaitCompletionPacket = 0xc9,
	NtCreateWnfStateName = 0xcb,
	NtDeleteWnfStateData = 0xd7,
	NtDeleteWnfStateName = 0xd8,
	NtFilterBootOption = 0xe3,
	NtFilterTokenEx = 0xe5,
	NtFlushBuffersFileEx = 0xe6,
	NtGetCachedSigningLevel = 0xf0,
	NtQueryWnfStateData = 0x163,
	NtQueryWnfStateNameInformation = 0x164,
	NtSetCachedSigningLevel = 0x189,
	NtSetInformationVirtualMemory = 0x19e,
	NtSetIRTimer = 0x194,
	NtSubscribeWnfStateChange = 0x1ba,
	NtUnmapViewOfSectionEx = 0x1cc,
	NtUnsubscribeWnfStateChange = 0x1cd,
	NtUpdateWnfStateData = 0x1ce,
	NtWaitForAlertByThreadId = 0x1d0,
	NtCancelTimer2 = 0x94,
	NtCreateTimer2 = 0xc3,
	NtGetCompleteWnfStateSubscription = 0xf1,
	NtSetTimer2 = 0x1ae,
	NtSetWnfProcessNotificationEvent = 0x1b3,
	NtAlpcImpersonateClientContainerOfPort = 0x85,
	NtCompareObjects = 0x9b,
	NtCreatePartition = 0xb6,
	NtGetCurrentProcessorNumberEx = 0xf4,
	NtManagePartition = 0x111,
	NtOpenPartition = 0x126,
	NtRevertContainerImpersonation = 0x17c,
	NtSetInformationSymbolicLink = 0x19a,
	NtCreateEnclave = 0xa8,
	NtInitializeEnclave = 0xfe,
	NtLoadEnclaveData = 0x106,
	NtCommitRegistryTransaction = 0x98,
	NtCreateRegistryTransaction = 0xbc,
	NtOpenRegistryTransaction = 0x129,
	NtQuerySecurityPolicy = 0x15c,
	NtRollbackRegistryTransaction = 0x17f,
	NtSetCachedSigningLevel2 = 0x18a,
	NtAcquireProcessActivityReference = 0x68,
	NtCompareSigningLevels = 0x9c,
	NtConvertBetweenAuxiliaryCounterAndPerformanceCounter = 0xa2,
	NtQueryAuxiliaryCounterFrequency = 0x13e,
	NtQueryInformationByName = 0x148,
	NtCallEnclave = 0x91,
	NtNotifyChangeDirectoryFileEx = 0x118,
	NtQueryDirectoryFileEx = 0x142,
	NtTerminateEnclave = 0x1be,
	NtAllocateVirtualMemoryEx = 0x76,
	NtMapViewOfSectionEx = 0x114,
	NtCreateSectionEx = 0xbe,
	NtManageHotPatch = 0x110,
	NtCreateCrossVmEvent = 0xa3,
	NtAcquireCrossVmMutant = 0x67,
	NtAllocateUserPhysicalPagesEx = 0x74,
	NtContinueEx = 0xa1,
	NtCreateCrossVmMutant = 0xa4,
	NtDirectGraphicsCall = 0xd9,
};

const char* print_syscall(const int value) {
	const char* s = nullptr;
#define PROCESS_VAL(p) case(p): s = #p; break;
	switch ((syscalls)value) {
		PROCESS_VAL(NtAcceptConnectPort);
		PROCESS_VAL(NtAccessCheck);
		PROCESS_VAL(NtAccessCheckAndAuditAlarm);
		PROCESS_VAL(NtAccessCheckByType);
		PROCESS_VAL(NtAccessCheckByTypeAndAuditAlarm);
		PROCESS_VAL(NtAccessCheckByTypeResultList);
		PROCESS_VAL(NtAccessCheckByTypeResultListAndAuditAlarm);
		PROCESS_VAL(NtAccessCheckByTypeResultListAndAuditAlarmByHandle);
		PROCESS_VAL(NtAddAtom);
		PROCESS_VAL(NtAddBootEntry);
		PROCESS_VAL(NtAddDriverEntry);
		PROCESS_VAL(NtAdjustGroupsToken);
		PROCESS_VAL(NtAdjustPrivilegesToken);
		PROCESS_VAL(NtAlertResumeThread);
		PROCESS_VAL(NtAlertThread);
		PROCESS_VAL(NtAllocateLocallyUniqueId);
		PROCESS_VAL(NtAllocateUserPhysicalPages);
		PROCESS_VAL(NtAllocateUuids);
		PROCESS_VAL(NtAllocateVirtualMemory);
		PROCESS_VAL(NtApphelpCacheControl);
		PROCESS_VAL(NtAreMappedFilesTheSame);
		PROCESS_VAL(NtAssignProcessToJobObject);
		PROCESS_VAL(NtCallbackReturn);
		PROCESS_VAL(NtCancelIoFile);
		PROCESS_VAL(NtCancelTimer);
		PROCESS_VAL(NtClearEvent);
		PROCESS_VAL(NtClose);
		PROCESS_VAL(NtCloseObjectAuditAlarm);
		PROCESS_VAL(NtCompactKeys);
		PROCESS_VAL(NtCompareTokens);
		PROCESS_VAL(NtCompleteConnectPort);
		PROCESS_VAL(NtCompressKey);
		PROCESS_VAL(NtConnectPort);
		PROCESS_VAL(NtContinue);
		PROCESS_VAL(NtCreateDebugObject);
		PROCESS_VAL(NtCreateDirectoryObject);
		PROCESS_VAL(NtCreateEvent);
		PROCESS_VAL(NtCreateEventPair);
		PROCESS_VAL(NtCreateFile);
		PROCESS_VAL(NtCreateIoCompletion);
		PROCESS_VAL(NtCreateJobObject);
		PROCESS_VAL(NtCreateJobSet);
		PROCESS_VAL(NtCreateKey);
		PROCESS_VAL(NtCreateKeyedEvent);
		PROCESS_VAL(NtCreateMailslotFile);
		PROCESS_VAL(NtCreateMutant);
		PROCESS_VAL(NtCreateNamedPipeFile);
		PROCESS_VAL(NtCreatePagingFile);
		PROCESS_VAL(NtCreatePort);
		PROCESS_VAL(NtCreateProcess);
		PROCESS_VAL(NtCreateProcessEx);
		PROCESS_VAL(NtCreateProfile);
		PROCESS_VAL(NtCreateSection);
		PROCESS_VAL(NtCreateSemaphore);
		PROCESS_VAL(NtCreateSymbolicLinkObject);
		PROCESS_VAL(NtCreateThread);
		PROCESS_VAL(NtCreateTimer);
		PROCESS_VAL(NtCreateToken);
		PROCESS_VAL(NtCreateWaitablePort);
		PROCESS_VAL(NtDebugActiveProcess);
		PROCESS_VAL(NtDebugContinue);
		PROCESS_VAL(NtDelayExecution);
		PROCESS_VAL(NtDeleteAtom);
		PROCESS_VAL(NtDeleteBootEntry);
		PROCESS_VAL(NtDeleteDriverEntry);
		PROCESS_VAL(NtDeleteFile);
		PROCESS_VAL(NtDeleteKey);
		PROCESS_VAL(NtDeleteObjectAuditAlarm);
		PROCESS_VAL(NtDeleteValueKey);
		PROCESS_VAL(NtDeviceIoControlFile);
		PROCESS_VAL(NtDisplayString);
		PROCESS_VAL(NtDuplicateObject);
		PROCESS_VAL(NtDuplicateToken);
		PROCESS_VAL(NtEnumerateBootEntries);
		PROCESS_VAL(NtEnumerateDriverEntries);
		PROCESS_VAL(NtEnumerateKey);
		PROCESS_VAL(NtEnumerateSystemEnvironmentValuesEx);
		PROCESS_VAL(NtEnumerateValueKey);
		PROCESS_VAL(NtExtendSection);
		PROCESS_VAL(NtFilterToken);
		PROCESS_VAL(NtFindAtom);
		PROCESS_VAL(NtFlushBuffersFile);
		PROCESS_VAL(NtFlushInstructionCache);
		PROCESS_VAL(NtFlushKey);
		PROCESS_VAL(NtFlushVirtualMemory);
		PROCESS_VAL(NtFlushWriteBuffer);
		PROCESS_VAL(NtFreeUserPhysicalPages);
		PROCESS_VAL(NtFreeVirtualMemory);
		PROCESS_VAL(NtFsControlFile);
		PROCESS_VAL(NtGetContextThread);
		PROCESS_VAL(NtGetCurrentProcessorNumber);
		PROCESS_VAL(NtGetDevicePowerState);
		PROCESS_VAL(NtGetWriteWatch);
		PROCESS_VAL(NtImpersonateAnonymousToken);
		PROCESS_VAL(NtImpersonateClientOfPort);
		PROCESS_VAL(NtImpersonateThread);
		PROCESS_VAL(NtInitializeRegistry);
		PROCESS_VAL(NtInitiatePowerAction);
		PROCESS_VAL(NtIsProcessInJob);
		PROCESS_VAL(NtIsSystemResumeAutomatic);
		PROCESS_VAL(NtListenPort);
		PROCESS_VAL(NtLoadDriver);
		PROCESS_VAL(NtLoadKey);
		PROCESS_VAL(NtLoadKey2);
		PROCESS_VAL(NtLoadKeyEx);
		PROCESS_VAL(NtLockFile);
		PROCESS_VAL(NtLockProductActivationKeys);
		PROCESS_VAL(NtLockRegistryKey);
		PROCESS_VAL(NtLockVirtualMemory);
		PROCESS_VAL(NtMakePermanentObject);
		PROCESS_VAL(NtMakeTemporaryObject);
		PROCESS_VAL(NtMapUserPhysicalPages);
		PROCESS_VAL(NtMapUserPhysicalPagesScatter);
		PROCESS_VAL(NtMapViewOfSection);
		PROCESS_VAL(NtModifyBootEntry);
		PROCESS_VAL(NtModifyDriverEntry);
		PROCESS_VAL(NtNotifyChangeDirectoryFile);
		PROCESS_VAL(NtNotifyChangeKey);
		PROCESS_VAL(NtNotifyChangeMultipleKeys);
		PROCESS_VAL(NtOpenDirectoryObject);
		PROCESS_VAL(NtOpenEvent);
		PROCESS_VAL(NtOpenEventPair);
		PROCESS_VAL(NtOpenFile);
		PROCESS_VAL(NtOpenIoCompletion);
		PROCESS_VAL(NtOpenJobObject);
		PROCESS_VAL(NtOpenKey);
		PROCESS_VAL(NtOpenKeyedEvent);
		PROCESS_VAL(NtOpenMutant);
		PROCESS_VAL(NtOpenObjectAuditAlarm);
		PROCESS_VAL(NtOpenProcess);
		PROCESS_VAL(NtOpenProcessToken);
		PROCESS_VAL(NtOpenProcessTokenEx);
		PROCESS_VAL(NtOpenSection);
		PROCESS_VAL(NtOpenSemaphore);
		PROCESS_VAL(NtOpenSymbolicLinkObject);
		PROCESS_VAL(NtOpenThread);
		PROCESS_VAL(NtOpenThreadToken);
		PROCESS_VAL(NtOpenThreadTokenEx);
		PROCESS_VAL(NtOpenTimer);
		PROCESS_VAL(NtPlugPlayControl);
		PROCESS_VAL(NtPowerInformation);
		PROCESS_VAL(NtPrivilegeCheck);
		PROCESS_VAL(NtPrivilegedServiceAuditAlarm);
		PROCESS_VAL(NtPrivilegeObjectAuditAlarm);
		PROCESS_VAL(NtProtectVirtualMemory);
		PROCESS_VAL(NtPulseEvent);
		PROCESS_VAL(NtQueryAttributesFile);
		PROCESS_VAL(NtQueryBootEntryOrder);
		PROCESS_VAL(NtQueryBootOptions);
		PROCESS_VAL(NtQueryDebugFilterState);
		PROCESS_VAL(NtQueryDefaultLocale);
		PROCESS_VAL(NtQueryDefaultUILanguage);
		PROCESS_VAL(NtQueryDirectoryFile);
		PROCESS_VAL(NtQueryDirectoryObject);
		PROCESS_VAL(NtQueryDriverEntryOrder);
		PROCESS_VAL(NtQueryEaFile);
		PROCESS_VAL(NtQueryEvent);
		PROCESS_VAL(NtQueryFullAttributesFile);
		PROCESS_VAL(NtQueryInformationAtom);
		PROCESS_VAL(NtQueryInformationFile);
		PROCESS_VAL(NtQueryInformationJobObject);
		PROCESS_VAL(NtQueryInformationPort);
		PROCESS_VAL(NtQueryInformationProcess);
		PROCESS_VAL(NtQueryInformationThread);
		PROCESS_VAL(NtQueryInformationToken);
		PROCESS_VAL(NtQueryInstallUILanguage);
		PROCESS_VAL(NtQueryIntervalProfile);
		PROCESS_VAL(NtQueryIoCompletion);
		PROCESS_VAL(NtQueryKey);
		PROCESS_VAL(NtQueryMultipleValueKey);
		PROCESS_VAL(NtQueryMutant);
		PROCESS_VAL(NtQueryObject);
		PROCESS_VAL(NtQueryOpenSubKeys);
		PROCESS_VAL(NtQueryOpenSubKeysEx);
		PROCESS_VAL(NtQueryPerformanceCounter);
		PROCESS_VAL(NtQueryPortInformationProcess);
		PROCESS_VAL(NtQueryQuotaInformationFile);
		PROCESS_VAL(NtQuerySection);
		PROCESS_VAL(NtQuerySecurityObject);
		PROCESS_VAL(NtQuerySemaphore);
		PROCESS_VAL(NtQuerySymbolicLinkObject);
		PROCESS_VAL(NtQuerySystemEnvironmentValue);
		PROCESS_VAL(NtQuerySystemEnvironmentValueEx);
		PROCESS_VAL(NtQuerySystemInformation);
		PROCESS_VAL(NtQueryTimer);
		PROCESS_VAL(NtQueryTimerResolution);
		PROCESS_VAL(NtQueryValueKey);
		PROCESS_VAL(NtQueryVirtualMemory);
		PROCESS_VAL(NtQueryVolumeInformationFile);
		PROCESS_VAL(NtQueueApcThread);
		PROCESS_VAL(NtRaiseException);
		PROCESS_VAL(NtRaiseHardError);
		PROCESS_VAL(NtReadFile);
		PROCESS_VAL(NtReadFileScatter);
		PROCESS_VAL(NtReadRequestData);
		PROCESS_VAL(NtReadVirtualMemory);
		PROCESS_VAL(NtRegisterThreadTerminatePort);
		PROCESS_VAL(NtReleaseKeyedEvent);
		PROCESS_VAL(NtReleaseMutant);
		PROCESS_VAL(NtReleaseSemaphore);
		PROCESS_VAL(NtRemoveIoCompletion);
		PROCESS_VAL(NtRemoveProcessDebug);
		PROCESS_VAL(NtRenameKey);
		PROCESS_VAL(NtReplaceKey);
		PROCESS_VAL(NtReplyPort);
		PROCESS_VAL(NtReplyWaitReceivePort);
		PROCESS_VAL(NtReplyWaitReceivePortEx);
		PROCESS_VAL(NtReplyWaitReplyPort);
		PROCESS_VAL(NtRequestPort);
		PROCESS_VAL(NtRequestWaitReplyPort);
		PROCESS_VAL(NtResetEvent);
		PROCESS_VAL(NtResetWriteWatch);
		PROCESS_VAL(NtRestoreKey);
		PROCESS_VAL(NtResumeProcess);
		PROCESS_VAL(NtResumeThread);
		PROCESS_VAL(NtSaveKey);
		PROCESS_VAL(NtSaveKeyEx);
		PROCESS_VAL(NtSaveMergedKeys);
		PROCESS_VAL(NtSecureConnectPort);
		PROCESS_VAL(NtSetBootEntryOrder);
		PROCESS_VAL(NtSetBootOptions);
		PROCESS_VAL(NtSetContextThread);
		PROCESS_VAL(NtSetDebugFilterState);
		PROCESS_VAL(NtSetDefaultHardErrorPort);
		PROCESS_VAL(NtSetDefaultLocale);
		PROCESS_VAL(NtSetDefaultUILanguage);
		PROCESS_VAL(NtSetDriverEntryOrder);
		PROCESS_VAL(NtSetEaFile);
		PROCESS_VAL(NtSetEvent);
		PROCESS_VAL(NtSetEventBoostPriority);
		PROCESS_VAL(NtSetHighEventPair);
		PROCESS_VAL(NtSetHighWaitLowEventPair);
		PROCESS_VAL(NtSetInformationDebugObject);
		PROCESS_VAL(NtSetInformationFile);
		PROCESS_VAL(NtSetInformationJobObject);
		PROCESS_VAL(NtSetInformationKey);
		PROCESS_VAL(NtSetInformationObject);
		PROCESS_VAL(NtSetInformationProcess);
		PROCESS_VAL(NtSetInformationThread);
		PROCESS_VAL(NtSetInformationToken);
		PROCESS_VAL(NtSetIntervalProfile);
		PROCESS_VAL(NtSetIoCompletion);
		PROCESS_VAL(NtSetLdtEntries);
		PROCESS_VAL(NtSetLowEventPair);
		PROCESS_VAL(NtSetLowWaitHighEventPair);
		PROCESS_VAL(NtSetQuotaInformationFile);
		PROCESS_VAL(NtSetSecurityObject);
		PROCESS_VAL(NtSetSystemEnvironmentValue);
		PROCESS_VAL(NtSetSystemEnvironmentValueEx);
		PROCESS_VAL(NtSetSystemInformation);
		PROCESS_VAL(NtSetSystemPowerState);
		PROCESS_VAL(NtSetSystemTime);
		PROCESS_VAL(NtSetThreadExecutionState);
		PROCESS_VAL(NtSetTimer);
		PROCESS_VAL(NtSetTimerResolution);
		PROCESS_VAL(NtSetUuidSeed);
		PROCESS_VAL(NtSetValueKey);
		PROCESS_VAL(NtSetVolumeInformationFile);
		PROCESS_VAL(NtShutdownSystem);
		PROCESS_VAL(NtSignalAndWaitForSingleObject);
		PROCESS_VAL(NtStartProfile);
		PROCESS_VAL(NtStopProfile);
		PROCESS_VAL(NtSuspendProcess);
		PROCESS_VAL(NtSuspendThread);
		PROCESS_VAL(NtSystemDebugControl);
		PROCESS_VAL(NtTerminateJobObject);
		PROCESS_VAL(NtTerminateProcess);
		PROCESS_VAL(NtTerminateThread);
		PROCESS_VAL(NtTestAlert);
		PROCESS_VAL(NtTraceEvent);
		PROCESS_VAL(NtTranslateFilePath);
		PROCESS_VAL(NtUnloadDriver);
		PROCESS_VAL(NtUnloadKey);
		PROCESS_VAL(NtUnloadKey2);
		PROCESS_VAL(NtUnloadKeyEx);
		PROCESS_VAL(NtUnlockFile);
		PROCESS_VAL(NtUnlockVirtualMemory);
		PROCESS_VAL(NtUnmapViewOfSection);
		PROCESS_VAL(NtVdmControl);
		PROCESS_VAL(NtWaitForDebugEvent);
		PROCESS_VAL(NtWaitForKeyedEvent);
		PROCESS_VAL(NtWaitForMultipleObjects);
		PROCESS_VAL(NtWaitForMultipleObjects32);
		PROCESS_VAL(NtWaitForSingleObject);
		PROCESS_VAL(NtWaitHighEventPair);
		PROCESS_VAL(NtWaitLowEventPair);
		PROCESS_VAL(NtWriteFile);
		PROCESS_VAL(NtWriteFileGather);
		PROCESS_VAL(NtWriteRequestData);
		PROCESS_VAL(NtWriteVirtualMemory);
		PROCESS_VAL(NtYieldExecution);
		PROCESS_VAL(NtAlpcAcceptConnectPort);
		PROCESS_VAL(NtAlpcCancelMessage);
		PROCESS_VAL(NtAlpcConnectPort);
		PROCESS_VAL(NtAlpcCreatePort);
		PROCESS_VAL(NtAlpcCreatePortSection);
		PROCESS_VAL(NtAlpcCreateResourceReserve);
		PROCESS_VAL(NtAlpcCreateSectionView);
		PROCESS_VAL(NtAlpcCreateSecurityContext);
		PROCESS_VAL(NtAlpcDeletePortSection);
		PROCESS_VAL(NtAlpcDeleteResourceReserve);
		PROCESS_VAL(NtAlpcDeleteSectionView);
		PROCESS_VAL(NtAlpcDeleteSecurityContext);
		PROCESS_VAL(NtAlpcDisconnectPort);
		PROCESS_VAL(NtAlpcImpersonateClientOfPort);
		PROCESS_VAL(NtAlpcOpenSenderProcess);
		PROCESS_VAL(NtAlpcOpenSenderThread);
		PROCESS_VAL(NtAlpcQueryInformation);
		PROCESS_VAL(NtAlpcQueryInformationMessage);
		PROCESS_VAL(NtAlpcRevokeSecurityContext);
		PROCESS_VAL(NtAlpcSendWaitReceivePort);
		PROCESS_VAL(NtAlpcSetInformation);
		PROCESS_VAL(NtCancelIoFileEx);
		PROCESS_VAL(NtCancelSynchronousIoFile);
		PROCESS_VAL(NtCommitComplete);
		PROCESS_VAL(NtCommitEnlistment);
		PROCESS_VAL(NtCommitTransaction);
		PROCESS_VAL(NtCreateEnlistment);
		PROCESS_VAL(NtCreateKeyTransacted);
		PROCESS_VAL(NtCreatePrivateNamespace);
		PROCESS_VAL(NtCreateResourceManager);
		PROCESS_VAL(NtCreateThreadEx);
		PROCESS_VAL(NtCreateTransaction);
		PROCESS_VAL(NtCreateTransactionManager);
		PROCESS_VAL(NtCreateUserProcess);
		PROCESS_VAL(NtCreateWorkerFactory);
		PROCESS_VAL(NtDeletePrivateNamespace);
		PROCESS_VAL(NtEnumerateTransactionObject);
		PROCESS_VAL(NtFlushInstallUILanguage);
		PROCESS_VAL(NtFlushProcessWriteBuffers);
		PROCESS_VAL(NtFreezeRegistry);
		PROCESS_VAL(NtFreezeTransactions);
		PROCESS_VAL(NtGetMUIRegistryInfo);
		PROCESS_VAL(NtGetNextProcess);
		PROCESS_VAL(NtGetNextThread);
		PROCESS_VAL(NtGetNlsSectionPtr);
		PROCESS_VAL(NtGetNotificationResourceManager);
		PROCESS_VAL(NtInitializeNlsFiles);
		PROCESS_VAL(NtIsUILanguageComitted);
		PROCESS_VAL(NtMapCMFModule);
		PROCESS_VAL(NtOpenEnlistment);
		PROCESS_VAL(NtOpenKeyTransacted);
		PROCESS_VAL(NtOpenPrivateNamespace);
		PROCESS_VAL(NtOpenResourceManager);
		PROCESS_VAL(NtOpenSession);
		PROCESS_VAL(NtOpenTransaction);
		PROCESS_VAL(NtOpenTransactionManager);
		PROCESS_VAL(NtPrepareComplete);
		PROCESS_VAL(NtPrepareEnlistment);
		PROCESS_VAL(NtPrePrepareComplete);
		PROCESS_VAL(NtPrePrepareEnlistment);
		PROCESS_VAL(NtPropagationComplete);
		PROCESS_VAL(NtPropagationFailed);
		PROCESS_VAL(NtQueryInformationEnlistment);
		PROCESS_VAL(NtQueryInformationResourceManager);
		PROCESS_VAL(NtQueryInformationTransaction);
		PROCESS_VAL(NtQueryInformationTransactionManager);
		PROCESS_VAL(NtQueryInformationWorkerFactory);
		PROCESS_VAL(NtQueryLicenseValue);
		PROCESS_VAL(NtReadOnlyEnlistment);
		PROCESS_VAL(NtRecoverEnlistment);
		PROCESS_VAL(NtRecoverResourceManager);
		PROCESS_VAL(NtRecoverTransactionManager);
		PROCESS_VAL(NtRegisterProtocolAddressInformation);
		PROCESS_VAL(NtReleaseWorkerFactoryWorker);
		PROCESS_VAL(NtRemoveIoCompletionEx);
		PROCESS_VAL(NtRollbackComplete);
		PROCESS_VAL(NtRollbackEnlistment);
		PROCESS_VAL(NtRollbackTransaction);
		PROCESS_VAL(NtRollforwardTransactionManager);
		PROCESS_VAL(NtSetInformationEnlistment);
		PROCESS_VAL(NtSetInformationResourceManager);
		PROCESS_VAL(NtSetInformationTransaction);
		PROCESS_VAL(NtSetInformationTransactionManager);
		PROCESS_VAL(NtSetInformationWorkerFactory);
		PROCESS_VAL(NtShutdownWorkerFactory);
		PROCESS_VAL(NtSinglePhaseReject);
		PROCESS_VAL(NtThawRegistry);
		PROCESS_VAL(NtThawTransactions);
		PROCESS_VAL(NtTraceControl);
		PROCESS_VAL(NtWaitForWorkViaWorkerFactory);
		PROCESS_VAL(NtWorkerFactoryWorkerReady);
		PROCESS_VAL(NtRenameTransactionManager);
		PROCESS_VAL(NtReplacePartitionUnit);
		PROCESS_VAL(NtAllocateReserveObject);
		PROCESS_VAL(NtCreateProfileEx);
		PROCESS_VAL(NtDisableLastKnownGood);
		PROCESS_VAL(NtDrawText);
		PROCESS_VAL(NtEnableLastKnownGood);
		PROCESS_VAL(NtNotifyChangeSession);
		PROCESS_VAL(NtOpenKeyEx);
		PROCESS_VAL(NtOpenKeyTransactedEx);
		PROCESS_VAL(NtQuerySecurityAttributesToken);
		PROCESS_VAL(NtQuerySystemInformationEx);
		PROCESS_VAL(NtQueueApcThreadEx);
		PROCESS_VAL(NtSerializeBoot);
		PROCESS_VAL(NtSetIoCompletionEx);
		PROCESS_VAL(NtSetTimerEx);
		PROCESS_VAL(NtUmsThreadYield);
		PROCESS_VAL(NtAddAtomEx);
		PROCESS_VAL(NtAdjustTokenClaimsAndDeviceGroups);
		PROCESS_VAL(NtAlertThreadByThreadId);
		PROCESS_VAL(NtAlpcConnectPortEx);
		PROCESS_VAL(NtAssociateWaitCompletionPacket);
		PROCESS_VAL(NtCancelWaitCompletionPacket);
		PROCESS_VAL(NtCreateDirectoryObjectEx);
		PROCESS_VAL(NtCreateIRTimer);
		PROCESS_VAL(NtCreateLowBoxToken);
		PROCESS_VAL(NtCreateTokenEx);
		PROCESS_VAL(NtCreateWaitCompletionPacket);
		PROCESS_VAL(NtCreateWnfStateName);
		PROCESS_VAL(NtDeleteWnfStateData);
		PROCESS_VAL(NtDeleteWnfStateName);
		PROCESS_VAL(NtFilterBootOption);
		PROCESS_VAL(NtFilterTokenEx);
		PROCESS_VAL(NtFlushBuffersFileEx);
		PROCESS_VAL(NtGetCachedSigningLevel);
		PROCESS_VAL(NtQueryWnfStateData);
		PROCESS_VAL(NtQueryWnfStateNameInformation);
		PROCESS_VAL(NtSetCachedSigningLevel);
		PROCESS_VAL(NtSetInformationVirtualMemory);
		PROCESS_VAL(NtSetIRTimer);
		PROCESS_VAL(NtSubscribeWnfStateChange);
		PROCESS_VAL(NtUnmapViewOfSectionEx);
		PROCESS_VAL(NtUnsubscribeWnfStateChange);
		PROCESS_VAL(NtUpdateWnfStateData);
		PROCESS_VAL(NtWaitForAlertByThreadId);
		PROCESS_VAL(NtCancelTimer2);
		PROCESS_VAL(NtCreateTimer2);
		PROCESS_VAL(NtGetCompleteWnfStateSubscription);
		PROCESS_VAL(NtSetTimer2);
		PROCESS_VAL(NtSetWnfProcessNotificationEvent);
		PROCESS_VAL(NtAlpcImpersonateClientContainerOfPort);
		PROCESS_VAL(NtCompareObjects);
		PROCESS_VAL(NtCreatePartition);
		PROCESS_VAL(NtGetCurrentProcessorNumberEx);
		PROCESS_VAL(NtManagePartition);
		PROCESS_VAL(NtOpenPartition);
		PROCESS_VAL(NtRevertContainerImpersonation);
		PROCESS_VAL(NtSetInformationSymbolicLink);
		PROCESS_VAL(NtCreateEnclave);
		PROCESS_VAL(NtInitializeEnclave);
		PROCESS_VAL(NtLoadEnclaveData);
		PROCESS_VAL(NtCommitRegistryTransaction);
		PROCESS_VAL(NtCreateRegistryTransaction);
		PROCESS_VAL(NtOpenRegistryTransaction);
		PROCESS_VAL(NtQuerySecurityPolicy);
		PROCESS_VAL(NtRollbackRegistryTransaction);
		PROCESS_VAL(NtSetCachedSigningLevel2);
		PROCESS_VAL(NtAcquireProcessActivityReference);
		PROCESS_VAL(NtCompareSigningLevels);
		PROCESS_VAL(NtConvertBetweenAuxiliaryCounterAndPerformanceCounter);
		PROCESS_VAL(NtQueryAuxiliaryCounterFrequency);
		PROCESS_VAL(NtQueryInformationByName);
		PROCESS_VAL(NtCallEnclave);
		PROCESS_VAL(NtNotifyChangeDirectoryFileEx);
		PROCESS_VAL(NtQueryDirectoryFileEx);
		PROCESS_VAL(NtTerminateEnclave);
		PROCESS_VAL(NtAllocateVirtualMemoryEx);
		PROCESS_VAL(NtMapViewOfSectionEx);
		PROCESS_VAL(NtCreateSectionEx);
		PROCESS_VAL(NtManageHotPatch);
		PROCESS_VAL(NtCreateCrossVmEvent);
		PROCESS_VAL(NtAcquireCrossVmMutant);
		PROCESS_VAL(NtAllocateUserPhysicalPagesEx);
		PROCESS_VAL(NtContinueEx);
		PROCESS_VAL(NtCreateCrossVmMutant);
		PROCESS_VAL(NtDirectGraphicsCall);
	default: s = nullptr;  break;
	}
#undef PROCESS_VAL

	return s;
}